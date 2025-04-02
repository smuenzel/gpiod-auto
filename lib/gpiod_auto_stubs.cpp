
#include <cppcaml.h>
#include <cppcaml2.h>

using namespace Cppcaml;

extern "C"
CAMLprim value x(value)
{
  return testCamlString.as_pointer();
}
