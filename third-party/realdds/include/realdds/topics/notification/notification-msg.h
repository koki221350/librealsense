// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2022 Intel Corporation. All Rights Reserved.

#pragma once


#include "notification.h"

#include <string>
#include <memory>
#include <vector>

#include <third-party/json_fwd.hpp>


namespace eprosima {
namespace fastdds {
namespace dds {
struct SampleInfo;
}
}  // namespace fastdds
}  // namespace eprosima


namespace realdds {


class dds_participant;
class dds_topic;
class dds_topic_reader;


namespace topics {

    
namespace raw {
class notificationPubSubType;
}  // namespace raw


class notification
{
public:
    using type = raw::notificationPubSubType;

    enum class data_format
    {
        // Note: these need to be kept in sync with the raw version
        JSON = raw::NOTIFICATION_DATA_JSON,
        CBOR = raw::NOTIFICATION_DATA_CBOR,
        CUSTOM = raw::NOTIFICATION_DATA_CUSTOM,
    };

    bool is_valid() const { return ! _data.empty(); }
    void invalidate() { _data.clear(); }

    static std::shared_ptr< dds_topic > create_topic( std::shared_ptr< dds_participant > const& participant,
        char const* topic_name );
    static std::shared_ptr< dds_topic > create_topic( std::shared_ptr< dds_participant > const& participant,
        std::string const& topic_name )
    {
        return create_topic( participant, topic_name.c_str() );
    }

    // This helper method will take the next sample from a reader.
    //
    // Returns true if successful. Make sure you still check is_valid() in case the sample info isn't!
    // Returns false if no more data is available.
    // Will throw if an unexpected error occurs.
    //
    static bool take_next( dds_topic_reader &,
                           notification * output,
                           eprosima::fastdds::dds::SampleInfo * optional_info = nullptr );


    notification() = default;
    notification( raw::notification && );
    notification( nlohmann::json const &, uint32_t version = 0 );
    notification( data_format format, nlohmann::json const &, uint32_t version = 0 );

    nlohmann::json json_data() const;

    // Get the custom data with casting to the desired type
    // Syntax: auto stream_info = msg.custom_data< STREAM_INFO >();
    //         if ( msg ) do something with it;
    template< typename T >
    T const * custom_data() const
    {
        return _data.size() > 0 ? reinterpret_cast< T const * >( _data.data() ) : nullptr;
    }
    template< typename T >
    T * custom_data()
    {
        return _data.size() > 0 ? reinterpret_cast< T * >( _data.data() ) : nullptr;
    }

    data_format _data_format;
    uint32_t _version = 0;
    std::vector< uint8_t > _data;
};


}  // namespace topics
}  // namespace realdds
