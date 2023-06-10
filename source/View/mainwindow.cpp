#include "mainwindow.h"
#include <QToolButton>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

MainWindow::MainWindow(QWidget*)
{

    QIcon icon("..\\..\\data\\logo.jpg");
    this->setWindowIcon(icon);
    this->setMinimumSize(QSize(1300, 800));
    mainLayout = new QVBoxLayout;
    createMenu();
    createSongTable();
    createSongButton();
    createPlaylistTable();
    createPlaylistButton();

    connect(playlistTable, &QTableWidget::itemSelectionChanged, this, &MainWindow::showPlaylistInfo);
    setLayout(mainLayout);
}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(tr("&About"), this, SLOT(onClickedAboutAction()));

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction("Open", this, SLOT(onClickedOpenAction()));
    fileMenu->addAction("Save as", this, SLOT(onClickedSaveAction()));
    fileMenu->addAction("Save playlist as", this, SLOT(onClickedSavePlaylistAction()));
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);
    mainLayout->addWidget(menuBar);
}

void MainWindow::createSongButton()
{
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    addSongButton = new QPushButton("add song");
    removeSongButton = new QPushButton("remove song");
    randomShuffleButton = new QPushButton("random shuffle");

    addSongButton->setFixedWidth(width() / 8);
    removeSongButton->setFixedWidth(width() / 8);
    randomShuffleButton->setFixedWidth(width() / 8);

    buttonLayout->setAlignment(Qt::AlignLeft);

    buttonLayout->addWidget(addSongButton);
    buttonLayout->addWidget(removeSongButton);
    buttonLayout->addWidget(randomShuffleButton);
    mainLayout->addLayout(buttonLayout);
    connectSongButton();
}

void MainWindow::createPlaylistButton()
{
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    addPlaylistButton = new QPushButton("add playlist");
    removePlaylistButton = new QPushButton("remove playlist");
    randomPlaylistButton = new QPushButton("random playlist");

    addPlaylistButton->setFixedWidth(width() / 8);
    removePlaylistButton->setFixedWidth(width() / 8);
    randomPlaylistButton->setFixedWidth(width() / 8);

    buttonLayout->setAlignment(Qt::AlignLeft);

    buttonLayout->addWidget(addPlaylistButton);
    buttonLayout->addWidget(removePlaylistButton);
    buttonLayout->addWidget(randomPlaylistButton);
    mainLayout->addLayout(buttonLayout);
    connectPlaylistButton();
}

void MainWindow::createSongTable()
{
    QHBoxLayout* songLayout = new QHBoxLayout;
    songsTable = new QTableWidget(0, 18);
    songsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headerLabels;
    headerLabels << "artist"
                 << "songs"
                 << "duration_ms"
                 << "explicit"
                 << "year"
                 << "popularity"
                 << "danceability"
                 << "energy"
                 << "key"
                 << "loudness"
                 << "mode"
                 << "speechiness"
                 << "acousticness"
                 << "instrumentalness"
                 << "liveness"
                 << "valence"
                 << "tempo"
                 << "tempo";
    songsTable->setHorizontalHeaderLabels(headerLabels);
    songLayout->addWidget(songsTable);
    mainLayout->addLayout(songLayout);
}

void MainWindow::createPlaylistTable()
{
    QHBoxLayout* playlistLayout = new QHBoxLayout;
    playlistTable = new QTableWidget(0, 2);
    playlistTable->setFixedWidth(width() / 2);
    playlistNameLabel = new QLabel("Name");
    descriptionLabel = new QLabel("Desicription");
    durationLabel = new QLabel("Duration");
    songsLabel = new QLabel("Songs");

    QStringList headerLabels2;
    headerLabels2 << "Name"
                  << "Track`s count";
    playlistTable->setHorizontalHeaderLabels(headerLabels2);
    playlistNameEdit = new QLineEdit();
    playlistNameEdit->setReadOnly(true);
    durationEdit = new QLineEdit();
    durationEdit->setReadOnly(true);
    descriptionEdit = new QLineEdit();
    descriptionEdit->setReadOnly(true);

    playlistssongsTable = new QTableWidget(0, 3);
    playlistssongsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headerLabels;
    headerLabels << "Song"
                 << "Artist"
                 << "Duration";
    playlistssongsTable->setHorizontalHeaderLabels(headerLabels);

    QVBoxLayout* playlistInfoLayout = new QVBoxLayout();
    playlistInfoLayout->setAlignment(Qt::AlignTop);
    QHBoxLayout* nameLayout = new QHBoxLayout();
    nameLayout->addWidget(playlistNameLabel);
    nameLayout->addWidget(playlistNameEdit);
    playlistInfoLayout->addLayout(nameLayout);

    QHBoxLayout* descriptionLayout = new QHBoxLayout();
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addWidget(descriptionEdit);
    playlistInfoLayout->addLayout(descriptionLayout);

    QHBoxLayout* durationLayout = new QHBoxLayout();
    durationLayout->addWidget(durationLabel);
    durationLayout->addWidget(durationEdit);
    playlistInfoLayout->addLayout(durationLayout);

    QHBoxLayout* songsLayout = new QHBoxLayout();
    songsLayout->addWidget(songsLabel);
    songsLayout->addWidget(playlistssongsTable);
    playlistInfoLayout->addLayout(songsLayout);

    QFrame* frame = new QFrame();
    frame->setLayout(playlistInfoLayout);

    playlistTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    playlistTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    playlistLayout->addWidget(playlistTable);
    playlistLayout->addWidget(frame);
    mainLayout->addLayout(playlistLayout);
}

void MainWindow::connectSongButton()
{
    connect(addSongButton, SIGNAL(clicked()), SLOT(onClickedAddSongButton()));
    connect(removeSongButton, SIGNAL(clicked()), SLOT(onClickedRemoveSongButton()));
    connect(randomShuffleButton, SIGNAL(clicked()), SLOT(onClickedRandomShuffleButton()));
}

void MainWindow::connectPlaylistButton()
{
    connect(addPlaylistButton, SIGNAL(clicked()), SLOT(onClickedAddPlaylistButton()));
    connect(removePlaylistButton, SIGNAL(clicked()), SLOT(onClickedRemovePlaylistButton()));
    connect(randomPlaylistButton, SIGNAL(clicked()), SLOT(onClickedRandomPlaylistButton()));
}

void MainWindow::setSongItem(const std::vector<TrackInfo>& infos)
{
    songsTable->clear();
    QStringList headerLabels;
    headerLabels << "artist"
                 << "songs"
                 << "duration_ms"
                 << "explicit"
                 << "year"
                 << "popularity"
                 << "danceability"
                 << "energy"
                 << "key"
                 << "loudness"
                 << "mode"
                 << "speechiness"
                 << "acousticness"
                 << "instrumentalness"
                 << "liveness"
                 << "valence"
                 << "tempo"
                 << "tempo";
    songsTable->setHorizontalHeaderLabels(headerLabels);
    songsTable->setRowCount(infos.size());
    songsTable->setColumnCount(18);

    for (int i = 0; i < infos.size(); ++i)
    {
        QTableWidgetItem* artistItem = new QTableWidgetItem(QString::fromStdString(infos[i].getArtist()));
        QTableWidgetItem* songItem = new QTableWidgetItem(QString::fromStdString(infos[i].getSong()));
        QTableWidgetItem* durationItem = new QTableWidgetItem(QString::number(infos[i].getDuration()));
        QTableWidgetItem* explicitItem = new QTableWidgetItem(QString::number(infos[i].isExplicit()));
        QTableWidgetItem* yearItem = new QTableWidgetItem(QString::number(infos[i].getYear()));
        QTableWidgetItem* popularityItem = new QTableWidgetItem(QString::number(infos[i].getPopularity()));
        QTableWidgetItem* danceabilityItem = new QTableWidgetItem(QString::number(infos[i].getDanceability()));
        QTableWidgetItem* energyItem = new QTableWidgetItem(QString::number(infos[i].getEnergy()));
        QTableWidgetItem* keyItem = new QTableWidgetItem(QString::number(infos[i].getKey()));
        QTableWidgetItem* loudnessItem = new QTableWidgetItem(QString::number(infos[i].getLoudness()));
        QTableWidgetItem* modeItem = new QTableWidgetItem(QString::number(infos[i].getMode()));
        QTableWidgetItem* speechinesItem = new QTableWidgetItem(QString::number(infos[i].getSpeechiness()));
        QTableWidgetItem* acousticnessItem = new QTableWidgetItem(QString::number(infos[i].getAcousticness()));
        QTableWidgetItem* instrumentalnessItem = new QTableWidgetItem(QString::number(infos[i].getInstrumentalness()));
        QTableWidgetItem* livenessItem = new QTableWidgetItem(QString::number(infos[i].getLiveness()));
        QTableWidgetItem* valenceItem = new QTableWidgetItem(QString::number(infos[i].getValence()));
        QTableWidgetItem* tempoItem = new QTableWidgetItem(QString::number(infos[i].getTempo()));
        QTableWidgetItem* genreItem = new QTableWidgetItem(QString::fromStdString(infos[i].getGenre()));
        songsTable->setItem(i, 0, artistItem);
        songsTable->setItem(i, 1, songItem);
        songsTable->setItem(i, 2, durationItem);
        songsTable->setItem(i, 3, explicitItem);
        songsTable->setItem(i, 4, yearItem);
        songsTable->setItem(i, 5, popularityItem);
        songsTable->setItem(i, 6, danceabilityItem);
        songsTable->setItem(i, 7, energyItem);
        songsTable->setItem(i, 8, keyItem);
        songsTable->setItem(i, 9, loudnessItem);
        songsTable->setItem(i, 10, modeItem);
        songsTable->setItem(i, 11, speechinesItem);
        songsTable->setItem(i, 12, acousticnessItem);
        songsTable->setItem(i, 13, instrumentalnessItem);
        songsTable->setItem(i, 14, livenessItem);
        songsTable->setItem(i, 15, valenceItem);
        songsTable->setItem(i, 16, tempoItem);
        songsTable->setItem(i, 17, genreItem);
    }
}

void MainWindow::setPlaylistItem(const std::vector<Playlist>& playlists)
{
    playlistssongsTable->clear();
    playlistNameEdit->clear();
    descriptionEdit->clear();
    durationEdit->clear();
    QStringList headerLabels;
    headerLabels << "Song"
                 << "Artist"
                 << "Duration";
    playlistssongsTable->setHorizontalHeaderLabels(headerLabels);
    QStringList headerLabels2;
    headerLabels << "Name"
                 << "Track`s count";
    playlistTable->setHorizontalHeaderLabels(headerLabels2);
    playlistTable->setRowCount(playlists.size());
    playlistTable->setColumnCount(2);
    for (int i = 0; i < playlists.size(); ++i)
    {
        playlistTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(playlists[i].getName())));
        playlistTable->setItem(i, 1, new QTableWidgetItem(QString::number(playlists[i].getInfos().size())));
    }
}

void MainWindow::setInfo(const std::vector<TrackInfo>& infos)
{
    setSongItem(infos);
}

void MainWindow::setPlaylistInfo(const std::vector<Playlist>& playlists)
{
    setPlaylistItem(playlists);
}

void MainWindow::onClickedAboutAction()
{
    ImageWidget* logo = new ImageWidget();
    QImage image;
    image.load("..\\..\\data\\logo.jpg");
    logo->setImage(image);
    logo->show();
}

void MainWindow::onClickedOpenAction()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open file"));
    emit openFileClickedSignal(filename.toStdString());
}

void MainWindow::onClickedSavePlaylistAction()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("save as"));
    emit saveAsPlaylistSignal(filename.toStdString());
}

void MainWindow::onClickedAddSongButton()
{
    SongInputDialog dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        QString artist = dialog.getArtist();
        QString song = dialog.getSong();
        int duration = dialog.getDuration();
        bool explicitContent = dialog.isExplicit();
        int year = dialog.getYear();
        int popularity = dialog.getPopularity();
        float danceability = dialog.getDanceability();
        float energy = dialog.getEnergy();
        long long key = dialog.getKey();
        float loudness = dialog.getLoudness();
        bool mode = dialog.isMajorMode();
        float speechines = dialog.getSpeechiness();
        float acousticness = dialog.getAcousticness();
        float instrumentalness = dialog.getInstrumentalness();
        float liveness = dialog.getLiveness();
        float valence = dialog.getValence();
        long long tempo = dialog.getTempo();
        QString genre = dialog.getGenre();

        if (artist != "" && song != "" && genre != "")
        {
            TrackInfo info(artist.toStdString(), song.toStdString(), duration, explicitContent, year, popularity,
                           danceability, energy, key, loudness, mode, speechines, acousticness,
                           instrumentalness, liveness, valence, tempo, genre.toStdString());
            emit clickedAddButtonSignal(info);
        }
    }
}

void MainWindow::onClickedRemoveSongButton()
{
    int i = songsTable->currentRow();

    if (i != -1)
        emit clickedRemoveButtonSignal(i);
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Incorrect");
        msgBox.setInformativeText("Select element");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int ret = msgBox.exec();
    }
}


void MainWindow::onClickedRandomShuffleButton()
{
    int rowCount = songsTable->rowCount();

    QList<int> rowIndices;
    for (int row = 0; row < rowCount; ++row)
    {
        rowIndices.append(row);
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(rowIndices.begin(), rowIndices.end(), generator);

    QTableWidget* tempTable = new QTableWidget(songsTable->rowCount(), songsTable->columnCount());

    for (int row = 0; row < songsTable->rowCount(); ++row)
    {
        for (int column = 0; column < songsTable->columnCount(); ++column)
        {
            QTableWidgetItem* originalItem = songsTable->item(row, column);
            if (originalItem)
            {
                QTableWidgetItem* newItem = new QTableWidgetItem(*originalItem);
                tempTable->setItem(row, column, newItem);
            }
        }
    }
    for (int row = 0; row < rowCount; ++row)
    {
        int originalRow = rowIndices[row];
        for (int column = 0; column < songsTable->columnCount(); ++column)
        {
            QTableWidgetItem* item = tempTable->takeItem(originalRow, column);
            songsTable->setItem(row, column, item);
        }
    }

    delete tempTable;
}

void MainWindow::onClickedAddPlaylistButton()
{

    QList<QTableWidgetItem*> selectedItems = songsTable->selectedItems();

    QSet<int> selectedRows;
    for (const QTableWidgetItem* item: selectedItems)
    {
        int row = item->row();
        selectedRows.insert(row);
    }
    if (selectedRows.empty())
    {
        return;
    }
    std::vector<std::vector<QTableWidgetItem*>> rowItems;

    for (int row: selectedRows)
    {
        std::vector<QTableWidgetItem*> rows;
        for (int column = 0; column < songsTable->columnCount(); ++column)
        {
            QTableWidgetItem* item = songsTable->item(row, column);
            if (item)
            {
                rows.push_back(item);
            }
        }
        rowItems.push_back(rows);
    }

    QString helpstr = "";
    std::vector<TrackInfo> infos;
    int sumDuration = 0;
    for (auto a: rowItems)
    {
        std::string artist = a[0]->text().toStdString();
        std::string song = a[1]->text().toStdString();
        int duration = a[2]->text().toInt();
        sumDuration += duration;
        bool explicitContent = a[3]->text().toInt();
        int year = a[4]->text().toInt();
        int popularity = a[5]->text().toInt();
        float danceability = a[6]->text().toFloat();
        float energy = a[7]->text().toFloat();
        long long key = a[8]->text().toLongLong();
        float loudness = a[9]->text().toFloat();
        bool mode = a[10]->text().toInt();
        float speechines = a[11]->text().toFloat();
        float acousticness = a[12]->text().toFloat();
        float instrumentalness = a[13]->text().toFloat();
        float liveness = a[14]->text().toFloat();
        float valence = a[15]->text().toFloat();
        long long tempo = a[16]->text().toLongLong();
        std::string genre = a[17]->text().toStdString();
        TrackInfo info(artist, song, duration, explicitContent, year, popularity, danceability, energy, key, loudness, mode, speechines, acousticness, instrumentalness, liveness, valence, tempo, genre);
        infos.push_back(info);
    }

    PlaylistDialog dialog;
    QString name = "";
    QString description = "";
    if (dialog.exec() == QDialog::Accepted)
    {
        name = dialog.getName();
        description = dialog.getDescription();
    }
    Playlist playlist(name.toStdString(), description.toStdString(), sumDuration, infos);
    emit addToPlaylistSignal(playlist);
}

void MainWindow::onClickedRemovePlaylistButton()
{
    QList<QTableWidgetItem*> selectedItems = playlistTable->selectedItems();

    QList<int> selectedRows;
    for (const QTableWidgetItem* item: selectedItems)
    {
        int row = item->row();
        if (!selectedRows.contains(row))
        {
            selectedRows.append(row);
        }
    }

    std::vector<int> indecies;
    for (int row: selectedRows)
    {
        indecies.push_back(row);
    }

    emit removeFromPlaylistSignal(indecies);
}


void MainWindow::onClickedRandomPlaylistButton()
{
    int count = songsTable->rowCount();
    if (count < 50)
    {
        QMessageBox msgBox;
        msgBox.setText("Incorrect");
        msgBox.setInformativeText("Add songs");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int ret = msgBox.exec();
        return;
    }
    std::vector<int> numbers;

    for (int i = 0; i <= count; ++i)
    {
        numbers.push_back(i);
    }

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(numbers.begin(), numbers.end(), generator);

    numbers.resize(50);

    std::vector<TrackInfo> infos;
    int sumDuration = 0;
    for (int i = 0; i < numbers.size(); ++i)
    {
        QTableWidgetItem* artistItem = songsTable->item(numbers[i], 0);
        QTableWidgetItem* songItem = songsTable->item(numbers[i], 1);
        QTableWidgetItem* durationItem = songsTable->item(numbers[i], 2);
        QTableWidgetItem* explicitItem = songsTable->item(numbers[i], 3);
        QTableWidgetItem* yearItem = songsTable->item(numbers[i], 4);
        QTableWidgetItem* popularityItem = songsTable->item(numbers[i], 5);
        QTableWidgetItem* danceabilityItem = songsTable->item(numbers[i], 6);
        QTableWidgetItem* energyItem = songsTable->item(numbers[i], 7);
        QTableWidgetItem* keyItem = songsTable->item(numbers[i], 8);
        QTableWidgetItem* loudnessItem = songsTable->item(numbers[i], 9);
        QTableWidgetItem* modeItem = songsTable->item(numbers[i], 10);
        QTableWidgetItem* speechinesItem = songsTable->item(numbers[i], 11);
        QTableWidgetItem* acousticnessItem = songsTable->item(numbers[i], 12);
        QTableWidgetItem* instrumentalnessItem = songsTable->item(numbers[i], 13);
        QTableWidgetItem* livenessItem = songsTable->item(numbers[i], 14);
        QTableWidgetItem* valenceItem = songsTable->item(numbers[i], 15);
        QTableWidgetItem* tempoItem = songsTable->item(numbers[i], 16);
        QTableWidgetItem* genreItem = songsTable->item(numbers[i], 17);
        TrackInfo info(artistItem->text().toStdString(), songItem->text().toStdString(), durationItem->text().toLongLong(), explicitItem->text().toInt(),
                       yearItem->text().toLongLong(), popularityItem->text().toLongLong(), danceabilityItem->text().toFloat(),
                       energyItem->text().toFloat(), keyItem->text().toLongLong(), loudnessItem->text().toFloat(), modeItem->text().toInt(),
                       speechinesItem->text().toFloat(), acousticnessItem->text().toFloat(), instrumentalnessItem->text().toFloat(), livenessItem->text().toFloat(),
                       valenceItem->text().toFloat(), tempoItem->text().toLongLong(), genreItem->text().toStdString());
        infos.push_back(info);
        sumDuration += durationItem->text().toInt();
    }
    Playlist playlist("random shuffle", "50 random tracks", sumDuration, infos);
    emit addToPlaylistSignal(playlist);
}

void MainWindow::showPlaylistInfo()
{
    int index = playlistTable->currentRow();
    emit showAdditionalInfoSignal(index);
}

void MainWindow::getPlaylistInfo(Playlist playlist)
{
    playlistNameEdit->setText(QString::fromStdString(playlist.getName()));
    descriptionEdit->setText(QString::fromStdString(playlist.getDescription()));
    durationEdit->setText(QString::number(playlist.getDuration()));
    QStringList headerLabels;
    headerLabels << "Song"
                 << "Artist"
                 << "Duration";
    playlistssongsTable->setHorizontalHeaderLabels(headerLabels);
    playlistssongsTable->setColumnCount(3);
    playlistssongsTable->setRowCount(playlist.getInfos().size());
    for (int i = 0; i < playlist.getInfos().size(); ++i)
    {
        playlistssongsTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(playlist.getInfos()[i].getSong())));
        playlistssongsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(playlist.getInfos()[i].getArtist())));
        playlistssongsTable->setItem(i, 2, new QTableWidgetItem(QString::number(playlist.getInfos()[i].getDuration())));
    }
}

void MainWindow::onClickedSaveAction()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("save as"));
    emit saveAsClickedSignal(filename.toStdString());
}