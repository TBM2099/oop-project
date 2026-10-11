#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "Image_Class.h"
#include "Filters.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadImage();
    void saveImage();
    void applySelectedFilter();

private:
    void updateImageDisplay();

    Image m_currentImage;
    bool m_isImageLoaded;

    QLabel *m_imageLabel;
    QComboBox *m_filterComboBox;
    QPushButton *m_loadButton;
    QPushButton *m_saveButton;
    QPushButton *m_applyButton;
};

#endif // MAINWINDOW_H