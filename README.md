# Udacity-Capstone

## Instructions for building/running the project

Step 1: Go to https://www.qt.io/download-open-source and download the Qt Online installer.
Step 2: Choose the appropraite folder to download Qt and chose custom installation.
![image](https://user-images.githubusercontent.com/69585981/126046236-2505b424-bc6c-4dfa-ac7d-9377c438084f.png)

Step 3 :Chose the appropriate components
![image](https://user-images.githubusercontent.com/69585981/126046345-9db46b60-54e2-47b7-9e64-24462b909967.png)

![image](https://user-images.githubusercontent.com/69585981/126046372-e42b1fee-6c45-4929-bf43-65625518423a.png)

Click Next
Step 4: Accept the Agreement and click Next
![image](https://user-images.githubusercontent.com/69585981/126046395-18391db6-2011-477a-b5ca-2d05d98b99a0.png)
 Step 5: Click next on subsequent pages until here
 ![image](https://user-images.githubusercontent.com/69585981/126046430-7d8aa47d-5fe8-4198-a379-b85d3624154f.png)
and Click install and Finish.

Open the project folder and click run on Qt Creator

## Text editing Application using Qt Creator
The text editing application has a similar look and feel to Notepad.

Shown below is waht is displayed on the console when the application is ran:
![image](https://user-images.githubusercontent.com/69585981/126046524-d0149026-50af-466e-bf39-370978360d83.png)

## Project Rubric
[Project.Rubric.xlsx](https://github.com/ao2-yekeen/Udacity-Capstone/files/6836621/Project.Rubric.xlsx)

## Code Structure:
Notepad.pro is a file that controls fow the project is going to be built and deployed.
## Notepad.h
Notepad.h contains the class Notepad which contains functions:
  void on_actionAbout_Notepad_triggered() 

    void on_actionNew_triggered();

    void on_actionOpen_triggered();
    void on_actionOpen_triggered(std::shared_ptr<Ui::Notepad> ui); //Function Overloading
    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

Each triggered when the user clicks the icon corresponding to the function names.
Notepad class controls everything on the main window.
The class Thread allows for multithreading in the application.

## main.cpp
QApplication a(argc, argv) is an instance of an application.
The main returns a.exec() which is necessary for the application to be executed.

## Notepad.ui
It contains an XML file that describes the user Interface  of the application

## Icons
This folder contains the icons used in the application

## Resource.qrc
This file manages the icons folder
