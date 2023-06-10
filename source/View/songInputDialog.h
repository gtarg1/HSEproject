#pragma once
#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>

class SongInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SongInputDialog(QWidget* parent = nullptr);

    QString getArtist() const;
    QString getSong() const;
    int getDuration() const;
    bool isExplicit() const;
    int getYear() const;
    int getPopularity() const;
    double getDanceability() const;
    double getEnergy() const;
    int getKey() const;
    double getLoudness() const;
    bool isMajorMode() const;
    double getSpeechiness() const;
    double getAcousticness() const;
    double getInstrumentalness() const;
    double getLiveness() const;
    double getValence() const;
    int getTempo() const;
    QString getGenre() const;

private:
    QLineEdit* artistLineEdit;
    QLineEdit* songLineEdit;
    QSpinBox* durationSpinBox;
    QCheckBox* explicitCheckBox;
    QSpinBox* yearSpinBox;
    QSpinBox* popularitySpinBox;
    QDoubleSpinBox* danceabilitySpinBox;
    QDoubleSpinBox* energySpinBox;
    QSpinBox* keySpinBox;
    QDoubleSpinBox* loudnessSpinBox;
    QCheckBox* modeCheckBox;
    QDoubleSpinBox* speechinessSpinBox;
    QDoubleSpinBox* acousticnessSpinBox;
    QDoubleSpinBox* instrumentalnessSpinBox;
    QDoubleSpinBox* livenessSpinBox;
    QDoubleSpinBox* valenceSpinBox;
    QSpinBox* tempoSpinBox;
    QLineEdit* genreLineEdit;
};