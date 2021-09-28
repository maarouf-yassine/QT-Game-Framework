#include "appmainview.h"

AppMainView::AppMainView()
{
    jsonUtils = new JsonUtils();
    signupPage = new SignupPage();
    menuPage = new mainPage();
    landingPage=new LandingPage();
    landingPage->show();

    connectButtons();
}

void AppMainView::connectButtons(){

    QObject::connect(signupPage->signUpB,SIGNAL(clicked(bool)),this,SLOT(openMainPage()));
    QObject::connect(signupPage->playAsGuestB,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(signupPage->signInB,SIGNAL(clicked(bool)),this,SLOT(login()));

    QObject::connect(landingPage->guestPushButton,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(landingPage->signUpPushButton,SIGNAL(clicked(bool)),this,SLOT(signup()));
    QObject::connect(landingPage->signInPushButton,SIGNAL(clicked(bool)),this,SLOT(openMainPage()));

}

void AppMainView::signup(){
    this->hide();
    landingPage->hide();
    signupPage->clearPage();
    signupPage->show();
}
void AppMainView::openMainPage(){
    if(signupPage->activeUser!=NULL){
        signupPage->close();
        //loginPage->activeUser = NULL;
        menuPage->activeUser = signupPage->activeUser;
        menuPage->welcomeL->setText(QString("Welcome, "+signupPage->activeUser->firstName+" "+signupPage->activeUser->lastName+"."));
        menuPage->addProfilePicture();
        menuPage->updateScores();
        this->setScene(menuPage);
        this->show();
    }
    //implement here else statement when we come from login page
    else if (landingPage->activeUser!=NULL){
        landingPage->close();
        menuPage->activeUser = signupPage->activeUser;
        menuPage->welcomeL->setText(QString("Welcome, "+signupPage->activeUser->firstName+" "+signupPage->activeUser->lastName+"."));
        menuPage->addProfilePicture();
        menuPage->updateScores();
        this->setScene(menuPage);
        this->show();
    }
}
void AppMainView::playAsGuest(){
    signupPage->hide();
    landingPage->hide();
    menuPage->clearPage();
    this->setScene(menuPage);
    this->show();
}
void AppMainView::login(){
    signupPage->close();
    signupPage->clearPage();
    landingPage->userNameLineEdit->clear();
    landingPage->passwordLineEdit->clear();
    landingPage->show();
}

void AppMainView::authenticateUser(){
    QString username =landingPage->userNameLineEdit->text();
    QString password=landingPage->passwordLineEdit->text();
    landingPage->activeUser=new User(jsonUtils->validateUser(username,password));
    openMainPage();
};
