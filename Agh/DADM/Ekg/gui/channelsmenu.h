#ifndef CHANNELSMENU_H
#define CHANNELSMENU_H

#include <QMenu>

class ChannelsPrivate;

class ChannelsMenu : public QMenu
{
    Q_OBJECT
public:
    explicit ChannelsMenu(QWidget *parent = 0);

	void clearChannels();
	void addChannel(const QString &name);
	void updateMenu();

private:
    void setSingleChoice(QList<QAction *> &list, QActionGroup *actionGroup = 0);

private:
    ChannelsPrivate *d;
};

#endif // CHANNELSMENU_H
