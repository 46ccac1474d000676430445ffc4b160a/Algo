#include "formulaclean.h"

QString formulaClean(const QString &f)
{
    QString func = f;
    return func.replace("$", "Math.").replace("exp", "#").replace("x", "%1", Qt::CaseInsensitive).replace("#", "exp");
}
