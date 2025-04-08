
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

DEF_CPPCAML(gpiod_chip_open, gpiod_chip_open, 1)
DEF_CPPCAML(gpiod_chip_get_info, gpiod_chip_get_info, 1)
