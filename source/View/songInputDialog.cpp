#include "SongInputDialog.h"

SongInputDialog::SongInputDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Song Input");

    artistLineEdit = new QLineEdit(this);
    songLineEdit = new QLineEdit(this);
    durationSpinBox = new QSpinBox(this);
    durationSpinBox->setRange(0, 9999999);
    explicitCheckBox = new QCheckBox(this);
    yearSpinBox = new QSpinBox(this);
    yearSpinBox->setRange(0, 9999999);
    popularitySpinBox = new QSpinBox(this);
    popularitySpinBox->setRange(0, 9999999);
    danceabilitySpinBox = new QDoubleSpinBox(this);
    popularitySpinBox->setRange(0, 9999999);
    energySpinBox = new QDoubleSpinBox(this);
    energySpinBox->setRange(0, 9999999);
    keySpinBox = new QSpinBox(this);
    keySpinBox->setRange(0, 9999999);
    loudnessSpinBox = new QDoubleSpinBox(this);
    loudnessSpinBox->setRange(0, 9999999);
    modeCheckBox = new QCheckBox(this);
    speechinessSpinBox = new QDoubleSpinBox(this);
    speechinessSpinBox->setRange(0, 9999999);
    acousticnessSpinBox = new QDoubleSpinBox(this);
    acousticnessSpinBox->setRange(0, 9999999);
    instrumentalnessSpinBox = new QDoubleSpinBox(this);
    instrumentalnessSpinBox->setRange(0, 9999999);
    livenessSpinBox = new QDoubleSpinBox(this);
    livenessSpinBox->setRange(0, 9999999);
    valenceSpinBox = new QDoubleSpinBox(this);
    valenceSpinBox->setRange(0, 9999999);
    tempoSpinBox = new QSpinBox(this);
    tempoSpinBox->setRange(0, 9999999);
    genreLineEdit = new QLineEdit(this);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Artist:", artistLineEdit);
    formLayout->addRow("Song:", songLineEdit);
    formLayout->addRow("Duration (ms):", durationSpinBox);
    formLayout->addRow("Explicit:", explicitCheckBox);
    formLayout->addRow("Year:", yearSpinBox);
    formLayout->addRow("Popularity:", popularitySpinBox);
    formLayout->addRow("Danceability:", danceabilitySpinBox);
    formLayout->addRow("Energy:", energySpinBox);
    formLayout->addRow("Key:", keySpinBox);
    formLayout->addRow("Loudness:", loudnessSpinBox);
    formLayout->addRow("Mode:", modeCheckBox);
    formLayout->addRow("Speechiness:", speechinessSpinBox);
    formLayout->addRow("Acousticness:", acousticnessSpinBox);
    formLayout->addRow("Instrumentalness:", instrumentalnessSpinBox);
    formLayout->addRow("Liveness:", livenessSpinBox);
    formLayout->addRow("Valence:", valenceSpinBox);
    formLayout->addRow("Tempo (BPM):", tempoSpinBox);
    formLayout->addRow("Genre:", genreLineEdit);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

QString SongInputDialog::getArtist() const { return artistLineEdit->text(); }
QString SongInputDialog::getSong() const { return songLineEdit->text(); }
int SongInputDialog::getDuration() const { return durationSpinBox->value(); }
bool SongInputDialog::isExplicit() const { return explicitCheckBox->isChecked(); }
int SongInputDialog::getYear() const { return yearSpinBox->value(); }
int SongInputDialog::getPopularity() const { return popularitySpinBox->value(); }
double SongInputDialog::getDanceability() const { return danceabilitySpinBox->value(); }
double SongInputDialog::getEnergy() const { return energySpinBox->value(); }
int SongInputDialog::getKey() const { return keySpinBox->value(); }
double SongInputDialog::getLoudness() const { return loudnessSpinBox->value(); }
bool SongInputDialog::isMajorMode() const { return modeCheckBox->isChecked(); }
double SongInputDialog::getSpeechiness() const { return speechinessSpinBox->value(); }
double SongInputDialog::getAcousticness() const { return acousticnessSpinBox->value(); }
double SongInputDialog::getInstrumentalness() const { return instrumentalnessSpinBox->value(); }
double SongInputDialog::getLiveness() const { return livenessSpinBox->value(); }
double SongInputDialog::getValence() const { return valenceSpinBox->value(); }
int SongInputDialog::getTempo() const { return tempoSpinBox->value(); }
QString SongInputDialog::getGenre() const { return genreLineEdit->text(); }