
#include <cppcaml.h>

#include <gpiod.h>

using namespace Cppcaml;

StaticCamlValue<1,0> testCamlValue;

static const StaticCamlString<to_array("hello")> testCamlString;

static const StaticCamlArray
< StaticCamlString<to_array("1")>
, StaticCamlString<to_array("12")>
, StaticCamlString<to_array("123")>
, StaticCamlString<to_array("1234")>
, StaticCamlString<to_array("12345")>
, StaticCamlString<to_array("123456")>
, StaticCamlString<to_array("1234567")>
, StaticCamlString<to_array("12345678")>
, StaticCamlString<to_array("123456789")>
 > testCamlArray;

extern "C"
CAMLprim value x(value)
{
  return (value)testCamlArray;
}

DEF_CPPCAML_ENUM(gpiod_line_value);
DEF_CPPCAML_ENUM(gpiod_line_direction);
DEF_CPPCAML_ENUM(gpiod_line_edge);
DEF_CPPCAML_ENUM(gpiod_line_bias);
DEF_CPPCAML_ENUM(gpiod_line_drive);
DEF_CPPCAML_ENUM(gpiod_line_clock);
DEF_CPPCAML_ENUM(gpiod_info_event_type);

template<>
struct Cppcaml::CamlType<gpiod_chip*>
: CamlTypeSharedPtrContainer<gpiod_chip, to_array("gpiod_chip"), FunDeleter<gpiod_chip_close>> { };

template<>
struct Cppcaml::CamlType<gpiod_chip_info*>
: CamlTypeSharedPtrContainer<gpiod_chip_info, to_array("gpiod_chip_info"), FunDeleter<gpiod_chip_info_free>> { };

template<>
struct Cppcaml::CamlType<gpiod_line_info*>
: CamlTypeSharedPtrContainer<gpiod_line_info, to_array("gpiod_line_info"), FunDeleter<gpiod_line_info_free>> { };

template<>
struct Cppcaml::CamlType<gpiod_info_event*>
: CamlTypeSharedPtrContainer<gpiod_info_event, to_array("gpiod_info_event"), FunDeleter<gpiod_info_event_free>> { };

template<>
struct Cppcaml::CamlType<gpiod_request_config*>
: CamlTypeSharedPtrContainer<gpiod_request_config, to_array("gpiod_request_config"), FunDeleter<gpiod_request_config_free>> { };

template<>
struct Cppcaml::CamlType<gpiod_line_config*>
: CamlTypeSharedPtrContainer<gpiod_line_config, to_array("gpiod_line_config"), FunDeleter<gpiod_line_config_free>> { };

template<>
struct Cppcaml::CamlType<gpiod_line_request*>
: CamlTypeSharedPtrContainer<gpiod_line_request, to_array("gpiod_line_request"), FunDeleter<gpiod_line_request_release>> { };

template<>
struct Cppcaml::CamlType<gpiod_line_settings*>
: CamlTypeSharedPtrContainer<gpiod_line_settings, to_array("gpiod_line_settings"), FunDeleter<gpiod_line_settings_free>> { };

static_assert(HasToCaml<NullablePointer<gpiod_request_config>>);
static_assert(HasOfCaml<NullablePointer<gpiod_request_config>>);


DEF_CPPCAML_S(gpiod_is_gpiochip_device, 1);
DEF_CPPCAML_S(gpiod_api_version, 1, AdapterNoArg);

DEF_CPPCAML_S(gpiod_chip_open, 1);
DEF_CPPCAML_S(gpiod_chip_get_info, 1);
DEF_CPPCAML_S(gpiod_chip_get_path, 1);
DEF_CPPCAML_S(gpiod_chip_get_line_info, 2);
DEF_CPPCAML_S(gpiod_chip_watch_line_info, 2);
DEF_CPPCAML_S(gpiod_chip_unwatch_line_info, 2);
DEF_CPPCAML_S(gpiod_chip_get_fd, 1);
DEF_CPPCAML_S(gpiod_chip_wait_info_event, 2);
DEF_CPPCAML_S(gpiod_chip_read_info_event, 1, AdapterNullableReturn);
DEF_CPPCAML_S(gpiod_chip_get_line_offset_from_name, 2);
DEF_CPPCAML_S(gpiod_chip_request_lines, 3, AdapterNullableReturn, AdapterNullable<1>);
DEF_CPPCAML_S(gpiod_chip_info_get_name, 1);
DEF_CPPCAML_S(gpiod_chip_info_get_label, 1);
DEF_CPPCAML_S(gpiod_chip_info_get_num_lines, 1);

DEF_CPPCAML_S(gpiod_line_info_copy, 1);
DEF_CPPCAML_S(gpiod_line_info_get_offset, 1);
DEF_CPPCAML_S(gpiod_line_info_get_name, 1);
DEF_CPPCAML_S(gpiod_line_info_is_used, 1);
DEF_CPPCAML_S(gpiod_line_info_get_consumer, 1);
DEF_CPPCAML_S(gpiod_line_info_get_bias, 1);
DEF_CPPCAML_S(gpiod_line_info_get_drive, 1);
DEF_CPPCAML_S(gpiod_line_info_is_active_low, 1);
DEF_CPPCAML_S(gpiod_line_info_is_debounced, 1);
DEF_CPPCAML_S(gpiod_line_info_get_debounce_period_us, 1);
DEF_CPPCAML_S(gpiod_line_info_get_event_clock, 1);
DEF_CPPCAML_S(gpiod_line_request_get_chip_name, 1);
DEF_CPPCAML_S(gpiod_line_request_get_num_requested_lines, 1);
//DEF_CPPCAML_S(gpiod_line_request_get_num_requested_offsets, 3);
DEF_CPPCAML_S(gpiod_line_request_get_value, 2);
//DEF_CPPCAML_S(gpiod_line_request_get_values_subset, 3);
//DEF_CPPCAML_S(gpiod_line_request_get_values, 2);
DEF_CPPCAML_S(gpiod_line_request_set_value, 3);
//DEF_CPPCAML_S(gpiod_line_request_set_values_subset, 3);
//DEF_CPPCAML_S(gpiod_line_request_set_values, 2);
DEF_CPPCAML_S(gpiod_line_request_reconfigure_lines, 2);
DEF_CPPCAML_S(gpiod_line_request_get_fd, 1);
DEF_CPPCAML_S(gpiod_line_request_wait_edge_events, 2);
//DEF_CPPCAML_S(gpiod_line_request_read_edge_events, 3);
DEF_CPPCAML_S(gpiod_info_event_get_event_type, 1);
DEF_CPPCAML_S(gpiod_info_event_get_timestamp_ns, 1);
DEF_CPPCAML_S(gpiod_info_event_get_line_info, 1);
DEF_CPPCAML_S(gpiod_line_settings_new, 1, AdapterNoArg);
DEF_CPPCAML_S(gpiod_line_settings_reset, 1);
DEF_CPPCAML_S(gpiod_line_settings_copy, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_direction, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_direction, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_edge_detection, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_edge_detection, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_bias, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_bias, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_drive, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_drive, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_active_low, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_active_low, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_debounce_period_us, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_debounce_period_us, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_event_clock, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_event_clock, 1);
DEF_CPPCAML_S(gpiod_line_settings_set_output_value, 2);
DEF_CPPCAML_S(gpiod_line_settings_get_output_value, 1);
DEF_CPPCAML_S(gpiod_line_config_new, 1, AdapterNoArg);
// DEF_CPPCAML_S(gpiod_line_config_add_line_settings, 4);
DEF_CPPCAML_S(gpiod_line_config_get_line_settings, 2);
//DEF_CPPCAML_S(gpiod_line_config_set_output_values, 3);
DEF_CPPCAML_S(gpiod_line_config_get_num_configured_offsets, 1);
// DEF_CPPCAML_S(gpiod_line_config_get_configured_offsets, 3);
DEF_CPPCAML_S(gpiod_request_config_new, 1, AdapterNoArg);
DEF_CPPCAML_S(gpiod_request_config_set_consumer, 2);
DEF_CPPCAML_S(gpiod_request_config_get_consumer, 1);
DEF_CPPCAML_S(gpiod_request_config_set_event_buffer_size, 2);
DEF_CPPCAML_S(gpiod_request_config_get_event_buffer_size, 1);



