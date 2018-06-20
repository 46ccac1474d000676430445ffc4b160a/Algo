#include "textedit_p.hpp"

#include <QChar>

bool p_isLetterOrNumber(const QChar &ch)
{
    QChar c = ch.toLower();
    int d = ( c.row() << 8 ) | c.cell();

    return (
             ('a' <= d && d <= 'z') ||
             ('0' <= d && d <= '9') ||
             (1072 <= d && d <= 1103) ||
             (d == 1105) ||
             (d == '-')
           );
}
