#include "controller.h"

Controller::Controller(MainWindow* view, CSVModel* model) : view_(view), model_(model)
{
}

void Controller::addSong(TrackInfo info)
{
    model_->modelAddSong(info);
}

void Controller::removeSong(int index)
{
    model_->modelRemoveSong(index);
}

void Controller::saveAsSong(const std::string& filename)
{
    model_->modelSaveSong(filename);
}

void Controller::addPlaylist(Playlist playlist)
{
    model_->modelAddPlaylist(playlist);
}

void Controller::additionalInfoPlaylist(int index)
{
    model_->modelAdditionalPlaylistInfo(index);
}

void Controller::removePlaylist(const std::vector<int>& indecies)
{
    model_->modelRemovePlaylist(indecies);
}

void Controller::saveAsPlaylist(const std::string& filename)
{
    model_->modelSavePlaylist(filename);
}

void Controller::initialize()
{
    view_ = new MainWindow();
    view_->show();
    connect(view_, &MainWindow::openFileClickedSignal, this, &Controller::parseSong);
    connect(model_, &CSVModel::updateSignal, view_, &MainWindow::setInfo);
    connect(view_, &MainWindow::clickedAddButtonSignal, this, &Controller::addSong);
    connect(view_, &MainWindow::clickedRemoveButtonSignal, this, &Controller::removeSong);
    connect(view_, &MainWindow::saveAsClickedSignal, this, &Controller::saveAsSong);
    connect(view_, &MainWindow::addToPlaylistSignal, this, &Controller::addPlaylist);
    connect(model_, &CSVModel::addPlaylist, view_, &MainWindow::setPlaylistInfo);
    connect(view_, &MainWindow::showAdditionalInfoSignal, this, &Controller::additionalInfoPlaylist);
    connect(model_, &CSVModel::showAdditionalInfoPlayList, view_, &MainWindow::getPlaylistInfo);
    connect(view_, &MainWindow::removeFromPlaylistSignal, this, &Controller::removePlaylist);
    connect(view_, &MainWindow::saveAsPlaylistSignal, this, &Controller::saveAsPlaylist);
}

void Controller::parseSong(const std::string& filename)
{
    model_->modelParseSong(filename);
}