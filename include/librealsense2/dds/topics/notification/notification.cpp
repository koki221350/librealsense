// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2022 Intel Corporation. All Rights Reserved.

/*!
 * @file notification.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "notification.h"
#include "notificationTypeObject.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

librealsense::dds::topics::raw::device::notification::notification()
{
    // m_id com.eprosima.idl.parser.typecode.PrimitiveTypeCode@587c290d
    m_id = 0;
    // m_size com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4ae82894
    m_size = 0;
    // m_raw_data com.eprosima.idl.parser.typecode.SequenceTypeCode@543788f3


    // Just to register all known types
    registernotificationTypes();
}

librealsense::dds::topics::raw::device::notification::~notification()
{



}

librealsense::dds::topics::raw::device::notification::notification(
        const notification& x)
{
    m_id = x.m_id;
    m_size = x.m_size;
    m_raw_data = x.m_raw_data;
}

librealsense::dds::topics::raw::device::notification::notification(
        notification&& x)
{
    m_id = x.m_id;
    m_size = x.m_size;
    m_raw_data = std::move(x.m_raw_data);
}

librealsense::dds::topics::raw::device::notification& librealsense::dds::topics::raw::device::notification::operator =(
        const notification& x)
{

    m_id = x.m_id;
    m_size = x.m_size;
    m_raw_data = x.m_raw_data;

    return *this;
}

librealsense::dds::topics::raw::device::notification& librealsense::dds::topics::raw::device::notification::operator =(
        notification&& x)
{

    m_id = x.m_id;
    m_size = x.m_size;
    m_raw_data = std::move(x.m_raw_data);

    return *this;
}

bool librealsense::dds::topics::raw::device::notification::operator ==(
        const notification& x) const
{

    return (m_id == x.m_id && m_size == x.m_size && m_raw_data == x.m_raw_data);
}

bool librealsense::dds::topics::raw::device::notification::operator !=(
        const notification& x) const
{
    return !(*this == x);
}

size_t librealsense::dds::topics::raw::device::notification::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    current_alignment += (100 * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);




    return current_alignment - initial_alignment;
}

size_t librealsense::dds::topics::raw::device::notification::getCdrSerializedSize(
        const librealsense::dds::topics::raw::device::notification& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.raw_data().size() > 0)
    {
        current_alignment += (data.raw_data().size() * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }




    return current_alignment - initial_alignment;
}

void librealsense::dds::topics::raw::device::notification::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_id;
    scdr << m_size;
    scdr << m_raw_data;

}

void librealsense::dds::topics::raw::device::notification::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_id;
    dcdr >> m_size;
    dcdr >> m_raw_data;
}

/*!
 * @brief This function sets a value in member id
 * @param _id New value for member id
 */
void librealsense::dds::topics::raw::device::notification::id(
        int16_t _id)
{
    m_id = _id;
}

/*!
 * @brief This function returns the value of member id
 * @return Value of member id
 */
int16_t librealsense::dds::topics::raw::device::notification::id() const
{
    return m_id;
}

/*!
 * @brief This function returns a reference to member id
 * @return Reference to member id
 */
int16_t& librealsense::dds::topics::raw::device::notification::id()
{
    return m_id;
}

/*!
 * @brief This function sets a value in member size
 * @param _size New value for member size
 */
void librealsense::dds::topics::raw::device::notification::size(
        uint32_t _size)
{
    m_size = _size;
}

/*!
 * @brief This function returns the value of member size
 * @return Value of member size
 */
uint32_t librealsense::dds::topics::raw::device::notification::size() const
{
    return m_size;
}

/*!
 * @brief This function returns a reference to member size
 * @return Reference to member size
 */
uint32_t& librealsense::dds::topics::raw::device::notification::size()
{
    return m_size;
}

/*!
 * @brief This function copies the value in member raw_data
 * @param _raw_data New value to be copied in member raw_data
 */
void librealsense::dds::topics::raw::device::notification::raw_data(
        const std::vector<uint8_t>& _raw_data)
{
    m_raw_data = _raw_data;
}

/*!
 * @brief This function moves the value in member raw_data
 * @param _raw_data New value to be moved in member raw_data
 */
void librealsense::dds::topics::raw::device::notification::raw_data(
        std::vector<uint8_t>&& _raw_data)
{
    m_raw_data = std::move(_raw_data);
}

/*!
 * @brief This function returns a constant reference to member raw_data
 * @return Constant reference to member raw_data
 */
const std::vector<uint8_t>& librealsense::dds::topics::raw::device::notification::raw_data() const
{
    return m_raw_data;
}

/*!
 * @brief This function returns a reference to member raw_data
 * @return Reference to member raw_data
 */
std::vector<uint8_t>& librealsense::dds::topics::raw::device::notification::raw_data()
{
    return m_raw_data;
}

size_t librealsense::dds::topics::raw::device::notification::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;






    return current_align;
}

bool librealsense::dds::topics::raw::device::notification::isKeyDefined()
{
    return false;
}

void librealsense::dds::topics::raw::device::notification::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
       
}





