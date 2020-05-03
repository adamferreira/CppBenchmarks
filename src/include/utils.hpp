
namespace cppbench {

#define CPP_98 1998
#define CPP_03 2003
#define CPP_11 2011
#define CPP_14 2014
#define CPP_17 2017
#define CPP_20 2020

#if (__cplusplus == 201103L)
  #define CPP_VERSION CPP_11
#elif (__cplusplus == 201402L)
  #define CPP_VERSION CPP_14
#elif (__cplusplus == 201703L)
  #define CPP_VERSION CPP_17
#elif (__cplusplus > 201703L)
	#define CPP_VERSION CPP_20
#else
  #define CPP_VERSION CPP_98
#endif

}