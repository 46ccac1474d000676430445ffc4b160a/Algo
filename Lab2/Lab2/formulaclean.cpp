#include "formulaclean.h"

QString formulaClean(const QString &f)
{
	QString func = f;
#define Replace(val) replace(#val, QString("Math.%1").arg(#val))
	func = func.Replace(sin);
	func = func.Replace(sinh);
	func = func.Replace(cos);
	func = func.Replace(cosh);
	func = func.Replace(tan);
	func = func.Replace(tanh);
	func = func.Replace(asin);
	func = func.Replace(asinh);
	func = func.Replace(acos);
	func = func.Replace(acosh);
	func = func.Replace(atan);
	func = func.Replace(atanh);
	func = func.Replace(abs);
	func = func.Replace(pow);
	func = func.Replace(E);
	func = func.Replace(PI);
#undef Replace
	func = func.replace("x", "%1");

	return func;
}
