#ifndef ADDRECORDHELPER_H
#define ADDRECORDHELPER_H

#include <QDialog>

class DatabaseHandler;

namespace Ui {
class AddRecordHelper;
}

class AddRecordHelper : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordHelper(QWidget *parent = 0);
    ~AddRecordHelper();
    void setDatabaseHandler(DatabaseHandler* dbh)
    {
        databaseHandler = dbh;
    }
    void clearTable();
    void updateTableHeaders(const int columns, const QStringList headersList);
    void addNewRow();
    void prepareIdColumn(const QString tableName);

private slots:
    void on_cancelAddingButton_clicked();
    void on_saveNewRecordButton_clicked();

private:
    Ui::AddRecordHelper *ui;
    DatabaseHandler *databaseHandler;
};

#endif // ADDRECORDHELPER_H
