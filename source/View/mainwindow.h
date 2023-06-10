#pragma once

#include "Source/Entity/playlist.h"
#include "Source/Entity/trackInfo.h"
#include "Source/Model/CSVModel.h"
#include "imagewidget.h"
#include "playlistDialog.h"
#include "songInputDialog.h"
#include <QAction>
#include <QComboBox>
#include <QDebug>
#include <QFileDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollBar>
#include <QTableWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

public slots:
    void setInfo(const std::vector<TrackInfo>& infos);
    void setPlaylistInfo(const std::vector<Playlist>& playlists);

    void onClickedAboutAction();
    void onClickedSaveAction();
    void onClickedOpenAction();
    void onClickedSavePlaylistAction();

    void onClickedAddSongButton();
    void onClickedRemoveSongButton();
    void onClickedRandomShuffleButton();

    void onClickedAddPlaylistButton();
    void onClickedRemovePlaylistButton();
    void onClickedRandomPlaylistButton();

    void showPlaylistInfo();
    void getPlaylistInfo(Playlist playlist);
signals:
    void openFileClickedSignal(const std::string& filename);
    void clickedAddButtonSignal(TrackInfo info);
    void clickedRemoveButtonSignal(int index);
    void saveAsClickedSignal(const std::string& filename);
    void addToPlaylistSignal(Playlist playlist);
    void showAdditionalInfoSignal(int index);
    void removeFromPlaylistSignal(const std::vector<int>& indecies);
    void saveAsPlaylistSignal(const std::string& filename);

private:
    void createMenu();

    void createSongButton();
    void createPlaylistButton();
    void createSongTable();
    void createPlaylistTable();

    void connectSongButton();
    void connectPlaylistButton();

    void setSongItem(const std::vector<TrackInfo>& infos);
    void setPlaylistItem(const std::vector<Playlist>& playlists);

    QMenuBar* menuBar;
    QMenu* helpMenu;
    QMenu* fileMenu;

    QTableWidget* songsTable;
    QTableWidget* playlistTable;
    QTableWidget* playlistssongsTable;

    QPushButton* addSongButton;
    QPushButton* removeSongButton;
    QPushButton* randomShuffleButton;

    QPushButton* addPlaylistButton;
    QPushButton* removePlaylistButton;
    QPushButton* randomPlaylistButton;

    QLabel* playlistNameLabel;
    QLabel* durationLabel;
    QLabel* descriptionLabel;
    QLabel* songsLabel;


    QLineEdit* playlistNameEdit;
    QLineEdit* durationEdit;
    QLineEdit* descriptionEdit;

    QVBoxLayout* mainLayout;
};