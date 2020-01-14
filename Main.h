#pragma once
#include "Admin.h"
#include "Waiter.h"
#include "Dessert.h"
#include "Drink.h"
#include "Entree.h"
#include "Mains.h"
#include "pch.h"
namespace RMSPOS {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;



ref class Main : public System::Windows::Forms::Form {
public:
    Main(void);

  void hideAll();

private:
  System::Windows::Forms::Panel ^ sidePanel;


  System::Windows::Forms::Button ^ adminButton;


  System::Windows::Forms::Button ^ clockButton;


  System::Windows::Forms::Button ^ dessertButton;


  System::Windows::Forms::Button ^ mainButton;


  System::Windows::Forms::Button ^ entreeButton;


  System::Windows::Forms::Button ^ drinkButton;


  System::Windows::Forms::Panel ^ footerPanel;


  System::Windows::Forms::Panel ^ headerPanel;


  System::Windows::Forms::Panel ^ clockinPanel;


  System::Windows::Forms::RichTextBox ^ staffnumberrichTextBox;


  System::Windows::Forms::Label ^ staffpasswordLabel;


  System::Windows::Forms::Label ^ staffnumberLabel;


  System::Windows::Forms::Button ^ clockOutbutton;


  System::Windows::Forms::Button ^ clockinButton;


  System::Windows::Forms::RichTextBox ^ staffpasswordrichTextBox;


  System::Windows::Forms::Panel ^ adminLoginPanel;


  System::Windows::Forms::RichTextBox ^ adminPasswordrichTextBox;


  System::Windows::Forms::Button ^ LoginButton;


  System::Windows::Forms::Label ^ adminPasswordLabel;


  System::Windows::Forms::Label ^ adminNumberLabel;


  System::Windows::Forms::RichTextBox ^ adminNumberrichTextBox;


  System::Windows::Forms::Panel ^ adminPanel;


  System::Windows::Forms::Button ^ orderSuppliesButton;


  System::Windows::Forms::TableLayoutPanel ^ drinksMenuPanel;


  System::Windows::Forms::Panel ^ contactPanel;


  System::Windows::Forms::PictureBox ^ Contact;


  System::Windows::Forms::Panel ^ removePanel;


  System::Windows::Forms::PictureBox ^ Remove;


  System::Windows::Forms::Panel ^ addPanel;


  System::Windows::Forms::Button ^ addMenuItemButton;


  System::Windows::Forms::PictureBox ^ Add;


  System::Windows::Forms::Panel ^ addItemPanel;


  System::Windows::Forms::Button ^ addDrinkButton;


  System::Windows::Forms::RichTextBox ^ itemPricerichTextBox;


  System::Windows::Forms::Label ^ itemPriceLabel;


  System::Windows::Forms::Label ^ itemNameLabel;


  System::Windows::Forms::RichTextBox ^ itemNamerichTextBox;


  System::Windows::Forms::ComboBox ^ itemCategory;


  System::Windows::Forms::Button ^ addWaiterButton;


  System::Windows::Forms::Button ^ removeWaiterButton;


  System::Windows::Forms::Button ^ removeMenuItemButton;


  System::Windows::Forms::TableLayoutPanel ^ entreeMenuPanel;


  System::Windows::Forms::TableLayoutPanel ^ mainMenuPanel;


  System::Windows::Forms::TableLayoutPanel ^ dessertMenuPanel;


  System::Windows::Forms::Label ^ errorLabel;


  System::Windows::Forms::Button ^ removeManagerButton;


  System::Windows::Forms::Button ^ addManagerButton;


  System::Windows::Forms::Panel ^ newAdminPanel;


  System::Windows::Forms::Label ^ salaryLabel;


  System::Windows::Forms::ComboBox ^ employmentTypeComboBox;


  System::Windows::Forms::RichTextBox ^ salaryrichTextBox;


  System::Windows::Forms::RichTextBox ^ addressrichTextBox;


  System::Windows::Forms::RichTextBox ^ agerichTextBox;


  System::Windows::Forms::RichTextBox ^ genderrichTextBox;


  System::Windows::Forms::Label ^ employmenttypeLabel;


  System::Windows::Forms::Label ^ addressLabel;


  System::Windows::Forms::Label ^ ageLabel;


  System::Windows::Forms::Label ^ genderLabel;


  System::Windows::Forms::RichTextBox ^ lastnamerichTextBox;


  System::Windows::Forms::Button ^ createnewadminButton;


  System::Windows::Forms::Label ^ lastnameLabel;


  System::Windows::Forms::Label ^ firstnameLabel;


  System::Windows::Forms::RichTextBox ^ firstnamerichTextBox;


  System::Windows::Forms::Label ^ loginFailedLabel;
  System::Windows::Forms::Button^ button2;
  System::Windows::Forms::Button^ button1;
  System::Windows::Forms::Panel^ newWaiterPanel;
  System::Windows::Forms::Label^ waiterSalaryLabel;
  System::Windows::Forms::ComboBox^ WaiterEmploymentTypeComboBox;
  System::Windows::Forms::RichTextBox^ waiterSalaryrichTextBox;
  System::Windows::Forms::RichTextBox^ waiterAddressrichTextBox;
  System::Windows::Forms::RichTextBox^ waiterAgerichTextBox;
  System::Windows::Forms::RichTextBox^ waiterGenderrichTextBox;
  System::Windows::Forms::Label^ waiterEmploymentTypeLabel;
  System::Windows::Forms::Label^ waiterAdressLabel;
  System::Windows::Forms::Label^ waiterAgeLabel;
  System::Windows::Forms::Label^ waiterGenderLabel;
  System::Windows::Forms::RichTextBox^ waiterLastNamerichTextBox;
  System::Windows::Forms::Button^ waiterCreateNewButton;
  System::Windows::Forms::Label^ waiterLastNameLabel;
  System::Windows::Forms::Label^ waiterFirstNameLabel;
  System::Windows::Forms::RichTextBox^ waiterFirstNamerichTextBox;
  System::Windows::Forms::Label^ clockinFailedLabel;



  System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

  void InitializeComponent(void);
#pragma endregion

    System::Void clockButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void adminButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void LoginButton_Click(System::Object^ sender,
        System::EventArgs^ e);



    System::Void drinkButton_Click(System::Object^ sender,
        System::EventArgs^ e);




    System::Void addMenuItemButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void addDrinkButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void entreeButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void mainButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void dessertButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void addManagerButton_Click(System::Object^ sender,
        System::EventArgs^ e);


    System::Void createnewadminButton_Click(System::Object^ sender,
        System::EventArgs^ e);
    System::Void addWaiterButton_Click(System::Object^ sender, System::EventArgs^ e);
    System::Void waiterCreateNewButton_Click(System::Object^ sender, System::EventArgs^ e);
    System::Void clockinButton_Click(System::Object^ sender, System::EventArgs^ e);
};
} // namespace RMSPOS
