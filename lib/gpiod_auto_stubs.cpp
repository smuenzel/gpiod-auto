
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

DEF_CPPCAML_S(gpiod_chip_open, 1);
DEF_CPPCAML_S(gpiod_chip_get_info, 1);
DEF_CPPCAML_S(gpiod_chip_get_path, 1);
DEF_CPPCAML_S(gpiod_chip_get_line_info, 2);
DEF_CPPCAML_S(gpiod_chip_watch_line_info, 2);
DEF_CPPCAML_S(gpiod_chip_unwatch_line_info, 2);
DEF_CPPCAML_S(gpiod_chip_get_fd, 1);
DEF_CPPCAML_S(gpiod_chip_wait_info_event, 2);
// CR smuenzel: nullable
DEF_CPPCAML_S(gpiod_chip_read_info_event, 1);
DEF_CPPCAML_S(gpiod_chip_get_line_offset_from_name, 2);
DEF_CPPCAML_S(gpiod_chip_request_lines, 3);
DEF_CPPCAML_S(gpiod_chip_info_get_name, 1);
DEF_CPPCAML_S(gpiod_chip_info_get_label, 1);
DEF_CPPCAML_S(gpiod_chip_info_get_num_lines, 1);

DEF_CPPCAML_S(gpiod_line_info_copy, 1);
DEF_CPPCAML_S(gpiod_line_info_get_offset, 1);
DEF_CPPCAML_S(gpiod_line_info_get_name, 1);
DEF_CPPCAML_S(gpiod_line_info_is_used, 1);
DEF_CPPCAML_S(gpiod_line_info_get_consumer, 1);
// DEF_CPPCAML_S(gpiod_line_info_get_bias, 1);



