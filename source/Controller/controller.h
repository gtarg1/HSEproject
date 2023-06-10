#pragma once

#include "Source/Entity/playlist.h"
#include "Source/Entity/trackInfo.h"
#include "Source/Model/CSVModel.h"
#include "Source/View/mainwindow.h"
#include <QObject>
#include <QTableWidgetItem>
#include <string>
#include <vector>
class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(MainWindow* view, CSVModel* model);
    ~Controller() = default;
private slots:
    void parseSong(const std::string& filename);
    void addSong(TrackInfo info);
    void removeSong(int index);
    void saveAsSong(const std::string& filename);

    void addPlaylist(Playlist playlist);
    void additionalInfoPlaylist(int index);
    void removePlaylist(const std::vector<int>& indecies);
    void saveAsPlaylist(const std::string& filename);

public:
    MainWindow* view_;
    CSVModel* model_;
    void initialize();
};