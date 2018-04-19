/********************************************
 * Titre: Travail pratique #6 - mainwindow.cpp
 * Date: 18 avril 2018
 * Modifier par: Amar Ghaly (1905322) & Yacer Razouani (1899606)
 *******************************************/
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStyle>
#include <QKeySequence>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include <QSlider>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <typeinfo>
#include <string>

#include "mainwindow.h"
#include "Gestionnaire.h"
#include "Usager.h"
#include "Fournisseur.h"
#include "ClientPremium.h"
#include "Client.h"
#include "ExceptionArgumentInvalide.h"

using namespace std;

Q_DECLARE_METATYPE(Usager*)

// Constructeur de la fenetre principale de l'application
MainWindow::MainWindow(Gestionnaire* gestionnaire, QWidget *parent) :
    QMainWindow(parent)
{
    gestionnaire_ = gestionnaire;
    setup();
}

MainWindow::~MainWindow() {
    while (!ajoute_.empty()) {
        delete ajoute_.back();
        ajoute_.pop_back();
    }
}

void MainWindow::setup() {
    indexCourantDuFiltre_ = 0;
    setMenu();
    setUI();
    setConnections();
    chargerUsagers();
}

/**
 * @brief MainWindow::setConnections, connecte les "signals" aux "slots" approprier
 * @param aucun
 * @return void
 */
void MainWindow::setConnections()
{
   /*À Faire*/
    connect(gestionnaire_, SIGNAL(usagerAjoute(Usager*)), SLOT(usagerAEteAjoute(Usager*)));
    connect(gestionnaire_, SIGNAL(usagerSupprime(Usager*)), SLOT(usagerAEteSupprime(Usager*)));

}

/**
 * @brief MainWindow::setMenu, le menu de l'interface
 * @param aucun
 * @return void
 */
void MainWindow::setMenu() {

    // On crée un bouton 'Exit'
    QAction* exit = new QAction(tr("&Quitter"), this);

    // On ajoute un raccourci clavier qui simulera l'appui sur ce bouton (Ctrl+Q)
    exit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

    // On connecte le clic sur ce bouton avec l'action de clore le programme
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    // On crée un nouveau menu 'File'
    QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));

    // Dans lequel on ajoute notre bouton 'Exit'
    fileMenu->addAction(exit);
}

/**
 * @brief MainWindow::setUI, l'interface et son design
 * @param aucun
 * @return void
 */
void MainWindow::setUI() {

    // Le sélecteur pour filtrer ce que l'on souhaite dans la liste (QComboBox*)
    /*À Faire*/
    QComboBox* showCombobox = new QComboBox(this);
    showCombobox->addItem("Tout Afficher");                 // Index 0
    showCombobox->addItem("Afficher Clients Reguliers");    // Index 1
    showCombobox->addItem("Afficher Clients Premiums");     // Index 2
    showCombobox->addItem("Afficher Fournisseurs");         // Index 3
    connect(showCombobox, SIGNAL(currentIndexChanged(int)),
                this, SLOT(filtrerListe(int)));

    // La liste des usagers
    listUsager = new QListWidget(this);
    listUsager->setSortingEnabled(true);
    connect(listUsager, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectionnerUsager(QListWidgetItem*)));

    // Le bouton pour supprimer tout le monde
    QPushButton* boutonSupprimerTousLesUsagers = new QPushButton(this);
    boutonSupprimerTousLesUsagers->setText("Supprimer Tous Les Usagers");
    connect(boutonSupprimerTousLesUsagers, SIGNAL(clicked()), this, SLOT(supprimerTousLesUsagers()));

    // Le bouton pour remettre à zéro la vue et ajouter un nouvel Usager
    /*À Faire*/
    QPushButton* boutonAjouterUsager = new QPushButton(this);
    boutonAjouterUsager->setText("Ajouter Nouveau Usager");
    connect(boutonAjouterUsager, SIGNAL(clicked()), this, SLOT(nettoyerVue()));

    // Le premier layout, pour la colonne de gauche, dans lequel on insère les
    // éléments que l'on veut dans l'ordre dans lequel on veut qu'ils apparaissent
    QVBoxLayout* listLayout = new QVBoxLayout;
    // à faire ajouter  le sélecteur
    listLayout->addWidget(listUsager);
    listLayout->addWidget(boutonSupprimerTousLesUsagers);
    listLayout->addWidget(boutonAjouterUsager);
    listLayout->addWidget(showCombobox);
    //listLayout->addWidget(nouvelUsager);
    // à faire ajouter le  nouveau usager

    // Champ pour le nom
    QLabel* nomLabel = new QLabel;
    nomLabel->setText("Nom:");
    editeurNom= new QLineEdit;

    QHBoxLayout* nomLayout = new QHBoxLayout;
    nomLayout->addWidget(nomLabel);
    nomLayout->addWidget(editeurNom);

    // Champ pour le prenom
    QLabel* prenomLabel = new QLabel;
    prenomLabel->setText("Prenom:");
    editeurPrenom = new QLineEdit;

    QHBoxLayout* prenomLayout = new QHBoxLayout;
    prenomLayout->addWidget(prenomLabel);
    prenomLayout->addWidget(editeurPrenom);

    //Champ pour l'identifiant avec validateur int entre 0 et 100 000
    /*À Faire*/
    QLabel* identifiantLabel = new QLabel;
    identifiantLabel->setText("Identifiant:");
    QIntValidator* valid = new QIntValidator(0, 100000, this);
    editeurIdentifiant= new QLineEdit;
    editeurIdentifiant->setValidator(valid);

    QHBoxLayout* identifiantLayout = new QHBoxLayout;
    identifiantLayout->addWidget(identifiantLabel);
    identifiantLayout->addWidget(editeurIdentifiant);

    // Champ pour le code postal
    /*À Faire*/
    QLabel* codePostalLabel = new QLabel;
    codePostalLabel->setText("Code Postal:");
    editeurCodePostal = new QLineEdit;

    QHBoxLayout* codePostalLayout = new QHBoxLayout;
    codePostalLayout ->addWidget(codePostalLabel);
    codePostalLayout ->addWidget(editeurCodePostal);

    //Champ pour JoursRestant de ClientPremium avec validateur int entre 0 et 1000
    /*À Faire*/
    QLabel* joursRestantLabel = new QLabel;
    joursRestantLabel->setText("Jours Restants:");
    QIntValidator *dayValidator = new QIntValidator(0, 1000, this);
    editeurJoursRestants= new QLineEdit;
    editeurJoursRestants->setValidator(dayValidator);

    QHBoxLayout* joursRestantLayout = new QHBoxLayout;
    joursRestantLayout->addWidget(joursRestantLabel);
    joursRestantLayout->addWidget(editeurJoursRestants);

    // Boutons radio
    QRadioButton* clientPremiumBoutonRadio = new QRadioButton("&ClientPremium", this);
    clientPremiumBoutonRadio->setChecked(true);
    boutonRadioTypeUsager.push_back(clientPremiumBoutonRadio);

    QRadioButton* clientRegulierBoutonRadio = new QRadioButton("&Client", this);
    boutonRadioTypeUsager.push_back(clientRegulierBoutonRadio);

    QRadioButton* fournisseurBoutonRadio = new QRadioButton("&Fournisseur", this);
    boutonRadioTypeUsager.push_back(fournisseurBoutonRadio);

    QButtonGroup* typeUsagerGroupeBoutons = new QButtonGroup;
    typeUsagerGroupeBoutons->addButton(clientPremiumBoutonRadio);
    typeUsagerGroupeBoutons->addButton(clientRegulierBoutonRadio);
    typeUsagerGroupeBoutons->addButton(fournisseurBoutonRadio);
    connect(typeUsagerGroupeBoutons, SIGNAL(buttonClicked(int)),
            this, SLOT(changerTypeUsager(int)));

    QHBoxLayout* typeUsagerLayout = new QHBoxLayout;
    typeUsagerLayout->addWidget(clientPremiumBoutonRadio);
    typeUsagerLayout->addWidget(clientRegulierBoutonRadio);
    typeUsagerLayout->addWidget(fournisseurBoutonRadio);

    // Trait horizontal de séparation
    QFrame* horizontalFrameLine = new QFrame;
    horizontalFrameLine->setFrameShape(QFrame::HLine);

    // Bouton pour supprimer l'usager sélectionné dans la liste
    /*À Faire*/
    boutonSupprimer= new QPushButton(this);
    boutonSupprimer->setText("Supprimer");
    connect(boutonSupprimer, SIGNAL(clicked()),
            this, SLOT(supprimerUsagerSelectionne()));

    // Bouton pour ajouter l'usager dont on
    // vient d'entrer les informations
    boutonAjouter = new QPushButton(this);
    boutonAjouter->setText("Ajouter");
    connect(boutonAjouter, SIGNAL(clicked()),
            this, SLOT(ajouterUsager()));

    // Organisation horizontale des boutons
    QHBoxLayout* ajouterSupprimerLayout = new QHBoxLayout;
    ajouterSupprimerLayout->addWidget(boutonAjouter);
    // À faire ajouter le bouton supprimé
    ajouterSupprimerLayout->addWidget(boutonSupprimer);

    // Organisation pour la colonne de droite
    // ajouter les 3 champs: identifiant, code postal, joursRestants
    QVBoxLayout* displayLayout = new QVBoxLayout;
    displayLayout->addLayout(nomLayout);
    displayLayout->addLayout(prenomLayout);
    displayLayout->addLayout(typeUsagerLayout);
    displayLayout->addWidget(horizontalFrameLine);
    displayLayout->addLayout(ajouterSupprimerLayout);
    displayLayout->addLayout(identifiantLayout);
    displayLayout->addLayout(codePostalLayout);
    displayLayout->addLayout(joursRestantLayout);

    // Trait vertical de séparation
    QFrame* verticalFrameLine = new QFrame;
    verticalFrameLine->setFrameShape(QFrame::VLine);

    // Organisation horizontale
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(listLayout);
    mainLayout->addWidget(verticalFrameLine);
    mainLayout->addLayout(displayLayout);

    // On crée un nouveau Widget, et on définit son
    // layout pour celui que l'on vient de créer
    QWidget* widget = new QWidget;
    widget->setLayout(mainLayout);

    // Puis on définit ce widget comme le widget
    // centrale de notre classe
    setCentralWidget(widget);

    // Enfin, on met à jour le titre de la fenêtre
    string title = "Gestionnaire de polebay!";
    setWindowTitle(title.c_str());
}

/**
 * @brief MainWindow::afficherMessage, cette fonction crée une boite de message de type popup
 * @param msg de type QString
 * @return void
 */
void MainWindow::afficherMessage(QString msg) {
    /*À Faire*/
    QMessageBox message;
    message.setText(msg);
    message.exec();
}

/**
 * @brief MainWindow::chargerUsagers, cette fonction charge tous les usagers connus
 * @param aucun
 * @return void
 */
void MainWindow::chargerUsagers() {
    // On s'assure que la liste est vide
    listUsager->clear();
    // Puis, pour tous les usagers
    int max = gestionnaire_->obtenirNombreUsager();
    for (int i = 0; i < max; i++) {
        // On récupère le pointeur vers l'employé
        Usager* usager = gestionnaire_->obtenirUsager(i);
        if (usager == nullptr) {
            continue;
        }
        // Et on l'ajoute en tant qu'item de la liste:
        // le nom et prenom sera affiché, et le pointeur sera contenu
        QListWidgetItem* item = new QListWidgetItem(
            QString::fromStdString(usager->obtenirNom()) + ", " + QString::fromStdString(usager->obtenirPrenom()), listUsager);
        item->setData(Qt::UserRole, QVariant::fromValue<Usager*>(usager));
        item->setHidden(filtrerMasque(usager));
    }
}

/**
 * @brief MainWindow::chargerUsagers, cette fonction retourne un boolean sur le type de filtre choisis
 * @param usager de type pointeur Usager
 * @return bool
 */
bool MainWindow::filtrerMasque(Usager* usager) {
    switch (indexCourantDuFiltre_) {
    case 1:
        return (typeid(*usager) != typeid(Client));
    case 2:
        return (typeid(*usager) != typeid(ClientPremium));
    case 3:
        return (typeid(*usager) != typeid(Fournisseur));
    case 0:
    default:
        return false;
    }
}

/**
 * @brief MainWindow::filtrerListe, cette fonction affiche les usagers d'un certain type selon l'index donné en paramètre
 * @param index de type int
 * @return void
 */
//Il s'agit des champs du dropdown menu ( Tous les usagers = 0 , Tous les clients reguliers = 1, tous les fournisseurs = 2...)
void MainWindow::filtrerListe(int index) {
    /*À Faire*/
    indexCourantDuFiltre_ = index;

    for (int i = 0; i < listUsager->count(); ++i) {
        QListWidgetItem *item = listUsager->item(i);
        Usager* user= item->data(Qt::UserRole).value<Usager*>();
        item->setHidden(filtrerMasque(user));
    }
}

/**
 * @brief MainWindow::selectionnerUsager, cette fonction affiche les informations de l'usager sélectionné à partir de la liste.
 * @param item de type pointeur QListWidgetItem
 * @return void
 */
//Ses informations sont affichées dans les boîtes de texte du panneau de droite.
//Les champs sont disabled à l'utilisateur pour éviter qu'il ne modifie l'objet
void MainWindow::selectionnerUsager(QListWidgetItem* item) {
    Usager* usager = item->data(Qt::UserRole).value<Usager*>();

    //Tous les champs sont mis à disabled et affiche l'information de l'usager sélectionné
    /*À Faire*/
    editeurNom->setDisabled(true);
    editeurNom->setText(QString::fromStdString(usager->obtenirNom()));

    editeurPrenom->setDisabled(true);
    editeurPrenom->setText(QString::fromStdString(usager->obtenirPrenom()));

    editeurIdentifiant->setDisabled(true);
    editeurIdentifiant->setText(QString::number(usager->obtenirIdentifiant()));

    editeurCodePostal->setDisabled(true);
    editeurCodePostal->setText(QString::fromStdString(usager->obtenirCodePostal()));

    //Affiche les jours restants s'il s'agit d'un ClientPremium, sinon on affiche "-"
    /*À Faire*/
    editeurJoursRestants->setDisabled(true);
    if (typeid(*usager) == typeid(ClientPremium)) {
        editeurJoursRestants->setText(QString("").arg(((ClientPremium*)usager)->obtenirJoursRestants()));
    } else {
        editeurJoursRestants->setText("-");
    }
    //On met a checked le type d'usager qui est sélectionné
    list<QRadioButton*>::iterator end = boutonRadioTypeUsager.end();
    for (list<QRadioButton*>::iterator it = boutonRadioTypeUsager.begin(); it != end; it++) {
        (*it)->setDisabled(true);

        bool checked = false;

        if ((typeid(*usager) == typeid(Client) && (*it)->text().endsWith("Client"))
             || (typeid(*usager) == typeid(ClientPremium) && (*it)->text().endsWith("ClientPremium"))
             || (typeid(*usager) == typeid(Fournisseur) && (*it)->text().endsWith("Fournisseur"))) {
                checked = true;
        }
        (*it)->setChecked(checked);
    }

    boutonAjouter->setDisabled(true);
    boutonSupprimer->setDisabled(false);
}

/**
 * @brief MainWindow::nettoyerVue, cette fonction remet à neuf la vue tel qu'on puisse y ajouter un nouvel usager
 * @param aucun
 * @return void
 */
void MainWindow::nettoyerVue() {
    editeurNom->setDisabled(false);
    editeurNom->setText("");

    editeurPrenom->setDisabled(false);
    editeurPrenom->setText("");

    editeurIdentifiant->setDisabled(false);
    editeurIdentifiant->setText("");

    editeurCodePostal->setDisabled(false);
    editeurCodePostal->setText("");

    editeurJoursRestants->setDisabled(false);
    editeurJoursRestants->setText("");

    //Par défaut le boutons radios est à ClientPremium
    list<QRadioButton*>::iterator end = boutonRadioTypeUsager.end();
    for (list<QRadioButton*>::iterator it = boutonRadioTypeUsager.begin(); it != end; it++) {
        (*it)->setDisabled(false);
        if ((*it)->text().endsWith("ClientPremium")) {
            (*it)->setChecked(true);
        }
    }

    listUsager->clearSelection();
    boutonAjouter->setDisabled(false);
    boutonSupprimer->setDisabled(true);
    editeurNom->setFocus();
}

/**
 * @brief MainWindow::changerTypeUsager
 * @param index de type int
 * @return void
 */
//Le champ JoursRestants est activé seulement s'il s'agit d'un ClientPremium
void MainWindow::changerTypeUsager(int index) {
    if (index == -2) {
        editeurJoursRestants->setDisabled(false);
    } else {
        editeurJoursRestants->setDisabled(true);
    }
}

/**
 * @brief MainWindow::supprimerTousLesUsagers, cette fonction supprime tous les usagers de la liste
 * @param aucun
 * @return void
 */
void MainWindow::supprimerTousLesUsagers() {
    /*À Faire*/
    vector<Usager*> aSupprimer;
    for (int i = 0; i < listUsager->count(); ++i) {
         QListWidgetItem *item = listUsager->item(i);
         aSupprimer.push_back(item->data(Qt::UserRole).value<Usager*>());
     }

     for (Usager* u : aSupprimer) {
         gestionnaire_->supprimerUsager(u);
     }
}

/**
 * @brief MainWindow::supprimerUsagerSelectionne, cette fonction supprime l'usager sélectionné dans la liste
 * @param aucun
 * @return void
 */
void MainWindow::supprimerUsagerSelectionne() {
    /*À Faire*/
    vector<Usager*> aSupprimer;
    for (QListWidgetItem *item : listUsager->selectedItems()) {
            aSupprimer.push_back(item->data(Qt::UserRole).value<Usager*>());
        }

     for (Usager* u : aSupprimer) {
         gestionnaire_->supprimerUsager(u);

     }
}

/**
 * @brief MainWindow::ajouterUsager, cette fonction ajoute un nouvel usager dans la liste
 * @param aucun
 * @return void
 */
void MainWindow::ajouterUsager() {

    Usager* nouvelUsager;

    /*À Faire*/

    //On trouve le bon type d'usager selon le bouton radio sélectionné
    /*...*/
    QRadioButton* selectedType = 0;
    list<QRadioButton*>::iterator end = boutonRadioTypeUsager.end();
    for (auto it = boutonRadioTypeUsager.begin(); it != end; it++) {
        if ((*it)->isChecked()) {
            selectedType = *it;
            break;
        }
    }

    //Utilisation d'un try throw catch pour faire un popup message si tous les champs ne sont pas remplis
    /*...*/

    try {
          string nom = editeurNom->text().toStdString();
          if (nom == "") {
              throw ExceptionArgumentInvalide("Erreur : Le champs nom est invalide! ");
          }
          string prenom = editeurPrenom->text().toStdString();
          if (prenom == "") {
              throw ExceptionArgumentInvalide("Erreur : Le champs prénom est invalide!");
          }
          bool ok;
          int identifiant = editeurIdentifiant->text().toInt(&ok);
          if (!ok) {
              throw ExceptionArgumentInvalide("Erreur : Le champs identifiant est invalide! ");
          }
          string codePostal= editeurCodePostal->text().toStdString();
          if (codePostal == "") {
              throw ExceptionArgumentInvalide("Erreur : Le champs code postal est invalide!");
          }
          // On créé le bon type d'usager selon le cas
          /*...*/
          if(selectedType->text().endsWith("ClientPremium"))
          {
              int joursRestants = editeurJoursRestants->text().toInt(&ok);
              if(!ok){
                  throw ExceptionArgumentInvalide("Erreur : Le champs nombre de jours restants est invalide! ");
              }
              nouvelUsager = new ClientPremium(editeurNom->text().toStdString(),
                                               editeurPrenom->text().toStdString(),
                                               editeurIdentifiant->text().toInt(),
                                               editeurCodePostal->text().toStdString(),
                                               editeurJoursRestants->text().toInt());
          } else if(selectedType->text().endsWith("Fournisseur")) {
              nouvelUsager = new Fournisseur(editeurNom->text().toStdString(),
                                           editeurPrenom->text().toStdString(),
                                          editeurIdentifiant->text().toInt(),
                                        editeurCodePostal->text().toStdString());
          } else
          {
             nouvelUsager = new Client(editeurNom->text().toStdString(),
                                       editeurPrenom->text().toStdString(),
                                          editeurIdentifiant->text().toInt(),
                                          editeurCodePostal->text().toStdString());
          }

    }catch (ExceptionArgumentInvalide& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Erreur lors de l'ajout d'un nouvel usager", e.what());
        return;
    }

    //Vérification que tous les champs ont été complétés
    /*.  ???????  ..*/


    // On ajoute le nouvel usager créé au gestionnaire
    /*...*/
    gestionnaire_->ajouterUsager(nouvelUsager);
    // Mais on le stocke aussi localement dans l'attribut ajoute_ pour pouvoir le supprimer plus tard
    /*...*/
    ajoute_.push_back(nouvelUsager);
}

/**
 * @brief MainWindow::usagerAEteAjoute, cette fonction met à jour la vue après l'ajout d'un usager
 * @param u de type pointeur Usager
 * @return void
 */
void MainWindow::usagerAEteAjoute(Usager* u) {
    /*À Faire*/
    // On ajoute le nouvel usager comme item de la QListWidget
    QListWidgetItem* item = new QListWidgetItem(
        QString::fromStdString(u->obtenirNom()) + ", " + QString::fromStdString(u->obtenirPrenom()), listUsager);
    item->setData(Qt::UserRole, QVariant::fromValue<Usager*>(u));


    // On change la visibilité de notre nouvel usager selon
    // le filtre actuel
    item->setHidden(filtrerMasque(u));

    ajoute_.push_back(u);
}

/**
 * @brief MainWindow::usagerAEteSupprime, cette fonction met à jour la vue après la suppression d'un usager
 * @param u de type pointeur Usager
 * @return void
 */
void MainWindow::usagerAEteSupprime(Usager* u) {
    // On cherche dans notre QlistWidget l'usager pour lequel le
    // signal a été envoyé, afin de l'en retirer
    for (int i = 0; i < listUsager->count(); ++i) {
        QListWidgetItem *item = listUsager->item(i);
        Usager* usager = item->data(Qt::UserRole).value<Usager*>();
        if (usager == u) {
            // delete sur un QlistWidget item va automatiquement le retirer de la liste

            delete item;
            // Si l'usager faisait partie de ceux créés localement, on veut le supprimer.
            auto it = std::find(ajoute_.begin(), ajoute_.end(), u);
            if (it != ajoute_.end()) {
                delete *it;
                ajoute_.erase(it);
            }
            break;
        }
    }
    // On remet à zéro l'affichage du panneau de gauche étant
    // donné que l'usager sélectionné a été supprimé
    nettoyerVue();
}
