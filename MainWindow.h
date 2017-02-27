#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>
#include <QRunnable>
#include <QThread>
#include <QTableWidgetItem>
#include "Launcher.h"
#include "MessageForm.h"
#include "TaskPool.h"

namespace Ui {
class MainWindow;
}

class AsyncBuildFragment : public QObject{
    Q_OBJECT
signals:
    void finished();

public slots:
    void start();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);

signals:


public slots:
    void on_btnRefreshTasks_clicked();
    void on_btnExportTask_clicked();
    void on_btnAddTasks_clicked();
    void on_btnRemoveTasks_clicked();
    void on_btnSaveTransMem_clicked();
    void on_btnNextFrag_clicked();
    void on_btnPrevFrag_clicked();
    void on_btnSaveFrag_clicked();
    void on_receivedEntryResponse(QString word, QStringList trans);
    void on_buildFragmentFinished();

private slots:
    void on_lstMenu_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_lstTaskFilter_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_btnWorkingDir_clicked();

    void on_lstTaskFilter_currentTextChanged(const QString &currentText);

    void on_btnStartTask_clicked();

    void on_txtOriginal_cursorPositionChanged();

    void on_txtOriginal_selectionChanged();

    void on_btnCommitTMs_clicked();

    void on_txtOriginal_customContextMenuRequested(const QPoint &pos);

    void on_tableEntries_itemChanged(QTableWidgetItem *item);

private:
    void initUI();
    void updateFileList(const QVector<QStringList> &data);
    void filterFileList(const QString& keyword);
    void restoreHistory();
    void saveHistory();
    void showEntriesTableAsync(const QStringList &header);
    void setCurrentFragment(int index = 0);

private:
    Ui::MainWindow *ui;
    Launcher *mLauncher;
    //TaskPool<std::thread> *mTaskPool;
    MessageForm *mMessageForm;
};

#endif // MAINWINDOW_H
