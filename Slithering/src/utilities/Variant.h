#ifndef _UTILITIES_VARIANT_H
#define _UTILITIES_VARIANT_H

namespace app::util
{
	// Initializes a template struct named overload
	// allows a special use of std::visit shown in 
	// https://www.bfilipek.com/2018/06/variant.html#overload
	// Usage:
	//	std::variant<int, double, float> number = 1.0;
	//	std::visit(overload{
	//		[](int & num) { num += 1; },
	//		[](double & num) { num += 2.0; },
	//		[](float & num) { num += 4.0f; }
	//	}, number);
	//
	// The above example will increment the variant by
	//   one if the variant is of type int;
	//   two if the variant is of type double;
	//   and four if the variant is of type float.
	//
	template<class... _Types> struct overload : _Types... { using _Types::operator()...; };
	template<class... _Types> overload(_Types...)->overload<_Types...>;
}

#endif // !_UTILITIES_VARIANT_H
