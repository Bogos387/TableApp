#ifndef MYTABLEDELEGATE_H
#define MYTABLEDELEGATE_H

#include <QStyledItemDelegate>

#include <QColor>


class MyTableDelegate : public QStyledItemDelegate
{
public:
    MyTableDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    void setColor(const QColor &f_color);


private:
    QColor color_;


};

#endif // MYTABLEDELEGATE_H
