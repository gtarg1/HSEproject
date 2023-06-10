#include "playlistDialog.h"
#include "playlist.h"

PlaylistDialog::PlaylistDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle("Playlist input");

    nameEdit = new QLineEdit(this);
    descriptionEdit = new QTextEdit(this);

    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("CANCEL", this);

    QFormLayout* layout = new QFormLayout(this);

    layout->addRow("Playlist name:", nameEdit);
    layout->addRow("Description:", descriptionEdit);

    layout->addRow(okButton, cancelButton);

    connect(okButton, &QPushButton::clicked, this, &PlaylistDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &PlaylistDialog::reject);
}

QString PlaylistDialog::getName() const
{
    return nameEdit->text();
}

QString PlaylistDialog::getDescription() const
{
    return descriptionEdit->toPlainText();
}