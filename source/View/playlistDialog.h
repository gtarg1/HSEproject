#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class PlaylistDialog : public QDialog
{
public:
    PlaylistDialog(QWidget* parent = nullptr);

    QString getName() const;

    QString getDescription() const;

private:
    QLineEdit* nameEdit;
    QTextEdit* descriptionEdit;
    QPushButton* okButton;
    QPushButton* cancelButton;
};
