#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include <QObject>

#include <QWidget>

namespace Ui {
    class OverviewPage;
}
class ClientModel;
class WalletModel;
class TxViewDelegate;
class TransactionFilterProxy;

QT_BEGIN_NAMESPACE
class QModelIndex;
class QTimer;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);
    void showOutOfSyncWarning(bool fShow);

public slots:
    void setBalance(qint64 balance, qint64 unconfirmedBalance, qint64 immatureBalance);
	void updateHotTimer();
	void showTime();

signals:
    void transactionClicked(const QModelIndex &index);
	//! Asynchronous message notification
    void message(const QString &title, const QString &message, unsigned int style);	

private:
    Ui::OverviewPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    qint64 currentBalance;
    qint64 currentUnconfirmedBalance;
    qint64 currentImmatureBalance;
	QTimer *hotTimer, *t_time;
	unsigned int hotTick;

    TxViewDelegate *txdelegate;
    TransactionFilterProxy *filter;
    bool bRequest;
private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex &index);
    void updateAlerts(const QString &warnings);
	void show_ovDefault();
};

#endif // OVERVIEWPAGE_H
