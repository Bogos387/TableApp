#include "my-table-delegate.h"

#include <QPainter>


MyTableDelegate::MyTableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
    , color_(Qt::green)
{

}


void MyTableDelegate::paint(QPainter *painter,
                            const QStyleOptionViewItem &option,
                            const QModelIndex &index) const
{
    if ((index.row() + 1) % 10 == 0)
    {
        painter->fillRect(option.rect, color_);
    }
    QStyledItemDelegate::paint(painter, option, index);
}


void MyTableDelegate::setColor(const QColor &f_color)
{
    this->color_ = f_color;
}
