#include <QtCore>
#include "booleanparser.h"


Node::Node(QString type, const QString &str,quint16 start,quint16 length)
{
    this->type = type;
    this->str = str;
    this->start = start;
    this->length = length;
    parent = 0;
}

Node::~Node()
{
    qDeleteAll(children);
}

