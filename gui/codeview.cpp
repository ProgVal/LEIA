#include "codeview.h"

CodeView::CodeView(QWidget *parent):
    QListWidget(parent), _machine(0)
{
    this->setUniformItemSizes(true);
}


void CodeView::update() {
    QStringList code;
    for (int i = 0; i < 0x10000; ++i) {
        code.append(QString::fromStdString(dissassemble(_machine->memory[i])));
    }
    this->clear();
    this->addItems(code);
    this->refresh();
}

void CodeView::updateCode(int row) {
    if (!_machine) return;
    QString foo = QString::fromStdString(dissassemble(_machine->memory[row]));
    if (row < this->count())
        this->item(row)->setText(foo);
}

void CodeView::setMachine(Machine &machine) {
    this->_machine = &machine;
}

void CodeView::refresh() {
    QListWidgetItem* item = 0;
    for(int i = 0; i < this->count(); ++i){
        item = this->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);

        item->setTextAlignment(Qt::AlignVCenter);
    }
}
