#include "guidedialog.hh"
#include "ui_guidedialog.h"

GuideDialog::GuideDialog(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::GuideDialog)
{
    ui_->setupUi(this);

    int width = ui_->HQLabel->width();
    int height = ui_->HQLabel->height();

    ui_->textLabel->setText("There is two players in this game: the player 1 is "
                            "black and the player 2\nis violet.\n\n"
                            "The goal of the game is to own as many tiles on "
                            "the game map as possible.\nThe game ends when "
                            "all tiles are owned by players. The winner "
                            "of the\ngame is the one who owns most tiles. A "
                            "draw is also possible to achieve.\n\n"
                            "A player obtain tiles by building on them. Building "
                            "can happen only on\nthose tiles, which are not owned "
                            "by another player. When building a\nheadquarters, the "
                            "player also gains ownership of neighbour tiles within "
                            "a\nradius of three tiles. In addition, when building "
                            "an outpost, the player\ngains ownership of neighbour "
                            "tiles within a radius of one tile. \n\n"
                            "The player needs resources for building. Resources "
                            "are also needed when\nhiring new workers. "
                            "A basic worker can be hired on a own farm or a own\n"
                            "boat. A miner can be hired on a own mine. A saboteur "
                            "can be hired on\nanother player's farm. Hiring a "
                            "saboteur subtracts another player's\nresources and "
                            "makes it impossible for another player to hire a "
                            "basic\nworker on the farm.\n\n"
                            "When the player owns a basic player or a miner, "
                            "the player achieves\nresources every time when "
                            "own turn begins. One turn contains one action.\n"
                            "The player can also skip turn.");

    // Images used in game:

    QPixmap HQImage(":/images/hq1");
    ui_->HQLabel->setPixmap(HQImage.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap outpostImage(":/images/outpost1");
    ui_->outpostLabel->setPixmap(outpostImage.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap farmImage(":/images/farm1");
    ui_->farmLabel->setPixmap(farmImage.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap boatImage(":/images/boat1");
    ui_->boatLabel->setPixmap(boatImage.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap mineImage(":/images/mine1");
    ui_->mineLabel->setPixmap(mineImage.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap HQImage2(":/images/hq2");
    ui_->HQLabel2->setPixmap(HQImage2.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap outpostImage2(":/images/outpost2");
    ui_->outpostLabel2->setPixmap(outpostImage2.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap farmImage2(":/images/farm2");
    ui_->farmLabel2->setPixmap(farmImage2.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap boatImage2(":/images/boat2");
    ui_->boatLabel2->setPixmap(boatImage2.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap mineImage2(":/images/mine2");
    ui_->mineLabel2->setPixmap(mineImage2.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap BWImage(":/images/worker1");
    ui_->BWLabel->setPixmap(BWImage.scaled(width + 30, height + 30, Qt::KeepAspectRatio));

    QPixmap minerImage(":/images/miner1");
    ui_->minerLabel->setPixmap(minerImage.scaled(width + 30, height + 30, Qt::KeepAspectRatio));

    QPixmap saboteurImage(":/images/saboteur1");
    ui_->saboteurLabel->setPixmap(saboteurImage.scaled(width + 30, height + 30, Qt::KeepAspectRatio));
}

GuideDialog::~GuideDialog() {
    delete ui_;
}

void GuideDialog::on_closeButton_clicked() {
    close();
}
