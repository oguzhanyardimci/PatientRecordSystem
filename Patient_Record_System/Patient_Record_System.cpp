#include "pch.h"
#include <iostream>
#include <fstream> 
#include <string> 
#include <stdio.h> 
#include <conio.h>
#include <windows.h> 
#include <clocale> 
#include <iomanip> 

using namespace std;

int main()
{
	system("color 4"); //Command window is colored
	setlocale(LC_ALL, "turkish"); //Added for Turkish Characters

	string PatientIdentityNumber;
	string PatientName;
	string PatientSurname;
	string PatientRegistNo;
	string PatientPhoneNumber;
	string PatientBirthday;
	string PatientGender;

	string QuerierIdentityNumber;
	string DeletedIdentityNumber;
	string IdentityNo;
	string UpdatingIdentityNo;
	string DeletedIdentityNo;
	string ExaminatedIdentityNo;

	string AppointmentDate;
	string AppointmentHour;
	string DoctorName;
	string Diagnosis;
	string Medication;
	string Test;

	double Fee;
	int selection, i = 1;
	char answer = 'y';

	do
	{
		cout << "1. Adding a Patient Record " << endl;
		cout << "2. Editing a Patient Record  " << endl;
		cout << "3. Deleting a Patient Record " << endl;
		cout << "4. Getting an Appointment " << endl;
		cout << "5. Updating an Appointment " << endl;
		cout << "6. Deleting Appointment " << endl;
		cout << "7. Examination Record of the Patient " << endl;
		cout << "8. Take the Patient List " << endl;
		cout << "9. Investigation the Patient " << endl;
		cout << "Select the action you want to do: "; 
		cin >> selection;
		cout << endl; //Input screen was created.
	} while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5 && selection != 6 && selection != 7 && selection != 8 && selection != 9);
	
	if (selection == 1)
		{
		system("cls"); //Input screen was cleaned at the all selection.  
		cout << "1. Adding a Patient Record" << endl;

		ofstream DosyaYaz; 

		DosyaYaz.open("Patient.txt", ios::app); //Patient.txt File was opened.

		do
		{
			cout << "   Patient Identity Number: "; cin >> PatientIdentityNumber;
			cout << "   Patient Name: "; cin >> PatientName;
			cout << "   Patient Surname: "; cin >> PatientSurname;
			cout << "   Patient Regist Number: "; cin >> PatientRegistNo;
			cout << "   Patient Phone Number: "; cin >> PatientPhoneNumber;
			cout << "   Patient Birthday: "; cin >> PatientBirthday;
			cout << "   Patient Gender: "; cin >> PatientGender;
			cout << endl;
			DosyaYaz << "\n" << PatientIdentityNumber << " " << PatientName << " " << PatientSurname << " " << PatientRegistNo << " " << PatientPhoneNumber << " " << PatientBirthday << " " << PatientGender;
			//The given information was written to Patient.txt file.

			cout << "   Patient Recording is completed." << endl;

			cout << "   Do you continue to record? [(Y)es/(N)o]: " ; 
			cin >> answer;
		} while (answer == 'y'); //If the answer is YES, continue to record.

		if (answer == 'n') //If the answer is NO, stop to record.
			DosyaYaz.close();
	}
	
	
	if (selection == 2)
	{
		system("cls"); 
		cout << "2. Editing a Patient Record" << endl;

		ifstream DosyaOku("Patient.txt"); //The command was written to exit from the file.
		ofstream DosyaYaz("TemporaryFile.tmp");//TemporaryFile.tmp file was created.
		// DosyaYaz.open("TemporaryFile.tmp",ios::app); 

		cout << "   Please, Enter the Identity Number to edit: "; 
		cin >> QuerierIdentityNumber; //Querier Identity Number was entered.

		int gcc = 0;
		while (!(DosyaOku.eof())) //Patient.txt File that was indicated was read to end of the file 
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;
			//Information that is in Patient.txt was read.

			if (QuerierIdentityNumber == PatientIdentityNumber) 
			{
				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;  
				//Personal Information is shown if the identity number that was entered are the same with another.

				cout << "   Patient Identity Number: " << PatientIdentityNumber << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;

				cout << "   Edit the Personal Patient Informations" << endl << endl;
				
				cout << "   Patient Name: "; cin >> PatientName;
				cout << "   Patient Surname: "; cin >> PatientSurname;
				cout << "   Patient Regist Number: "; cin >> PatientRegistNo;
				cout << "   Patient Phone Number: "; cin >> PatientPhoneNumber;
				cout << "   Patient Birthday: "; cin >> PatientBirthday;
				cout << "   Patient Gender: "; cin >> PatientGender;

				DosyaYaz << "\n" << QuerierIdentityNumber << " " << PatientName << " " << PatientSurname << " " << PatientRegistNo << " " << PatientPhoneNumber << " " << PatientBirthday << " " << PatientGender;
				//The regulated information was written.

				gcc = 1;
			}
			else
			{
				DosyaYaz << "\n" << PatientIdentityNumber << " " << PatientName << " " << PatientSurname << " " << PatientRegistNo << " " << PatientPhoneNumber << " " << PatientBirthday << " " << PatientGender;
			}
		}
		if (gcc == 0)
		{
			cout << "   There is no registry. Please, enter the true Identity Number." << endl;
		}
			DosyaYaz.close();
			DosyaOku.close();

			remove("Patient.txt");
			rename("TemporaryFile.tmp", "Patient.txt");
			//In the last 2 lines, Patient.txt File was deleted and TemporaryFile.tmp File was altered as Patient.txt

	}
	
	if (selection == 3)
	{
		system("cls");
		cout << "3. Deleting a Patient Record" << endl;
	
		cout << "   Please, Enter the Deleted Identity Number: "; 
		cin >> DeletedIdentityNumber;
		cout << endl;

		ifstream DosyaOku("Patient.txt");
		ofstream DosyaYaz("TemporaryFile.tmp"); //TemporaryFile was opened.

		while (!(DosyaOku.eof())) //The indicated Patient.txt File  was read to end of the file. 
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;

			if (PatientIdentityNumber == DeletedIdentityNumber)
			{

				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

				cout << "   Patient Identity Number: " << DeletedIdentityNumber << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;  
				
				cout << "   Deleting Process was done.. " << endl;
				break;
			}
			
			else
				DosyaYaz << "\n" << PatientIdentityNumber << " " << PatientName << " " << PatientSurname << " " << PatientRegistNo << " " << PatientPhoneNumber << " " << PatientBirthday << " " << PatientGender;
			
		}

		DosyaYaz.close();
		DosyaOku.close();

		remove("Patient.txt"); //The Patient.txt file was deleted.
		rename("TemporaryFile.tmp", "Patient.txt"); //TemporaryFile.tmp files was transfered to  Patient.txt after the deleting.

	}

	if (selection == 4)
	{
		system("cls"); 
		cout << "4. Getting an Appointment" << endl;

		cout << "   Please, Enter the Identity Number: "; 
		cin >> IdentityNo;

		ifstream DosyaOku("Patient.txt");
		ofstream DosyaYaz("Patient.txt", ios::app);

		int gcc = 0;
		while (!DosyaOku.eof())  //The indicated Patient.txt File  was read to end of the file. 
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;

			if (IdentityNo == PatientIdentityNumber) 
			{
				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

				cout << "   Patient Identity Number: " << PatientIdentityNumber << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;

				gcc = 1;
			}

		}
		if (gcc == 0)
		{
			cout << "   There is no registry. Please, generate a patient recording. " << endl;
			cout << "   Enter the Identity Number: "; cin >> IdentityNo;
			cout << "   Enter the Patient Name: "; cin >> PatientName;
			cout << "   Enter the Patient Surname: "; cin >> PatientSurname;
			cout << "   Enter the Patient Regist Number: "; cin >> PatientRegistNo;
			cout << "   Enter the Patient Phone Number: "; cin >> PatientPhoneNumber;
			cout << "   Enter the Patient Birthday: "; cin >> PatientBirthday;
			cout << "   Enter the Patient Gender: "; cin >> PatientGender;

			DosyaYaz << "\n" << PatientIdentityNumber << " " << PatientName << " " << PatientSurname << " " << PatientRegistNo << " " << PatientPhoneNumber << " " << PatientBirthday << " " << PatientGender;
			cout << endl;
			cout << "   Patient recording is completed." << endl;
		}
		cout << "   Would you like to make appointment? [(Y)es/(N)o]: ";
		cin >> answer;

		if (answer == 'y')
		{
			DosyaOku.close();
			DosyaYaz.close();
			ofstream DosyaYaz;
			DosyaYaz.open("Appointment.txt", ios::app);

			cout << endl;
			cout << "   APPOINTMENT INFORMATIONS" << endl;
			cout << "   Appointment Date: "; cin >> AppointmentDate;
			cout << "   Appointment Hour: "; cin >> AppointmentHour;
			cout << "   Doctor Name: "; cin >> DoctorName;

			DosyaYaz << "\n" << IdentityNo << " " << AppointmentDate << " " << AppointmentHour << " " << DoctorName << " " << "-" << " " << "-" << " " << "-" << "\n";
			cout << "   Appointment Registration was done." << endl;
			DosyaYaz.close();
		}
		else
			cout << "   Transaction was executed." << endl;
	}

	if (selection == 5)
	{
		system("cls"); 
		cout << "5. Updating the Appointment" << endl;

		cout << "   Please, Enter the Identity Number to update: "; 
		cin >> UpdatingIdentityNo;

		ifstream DosyaOku("Patient.txt");
		int gcc = 0;
		while (!(DosyaOku.eof())) //The indicated Patient.txt File  was read to end of the file. 
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;
			if (PatientIdentityNumber == UpdatingIdentityNo)
			{
				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

				cout << "   Patient Identity Number: " << PatientIdentityNumber << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;
			}
		}

		ifstream DosyaOku2("Appointment.txt");
		while (!(DosyaOku2.eof())) //The indicated Patient.txt File  was read to end of the file. 
		{
			DosyaOku2 >> PatientIdentityNumber >> AppointmentDate >> AppointmentHour >> DoctorName;
			if (PatientIdentityNumber == UpdatingIdentityNo)
			{
				cout << "   EXISTING APPOINTMENT INFORMATIONS" << endl;

				cout << "   Identity Number: " << UpdatingIdentityNo << endl;
				cout << "   Appointment Date: " << AppointmentDate << endl;
				cout << "   Appointment Hour: " << AppointmentHour << endl;
				cout << "   Doctor Name: " << DoctorName << endl;
				DosyaOku2.close();
				break;
			}
		}
		ifstream RandevuDosyaOku("Appointment.txt"); //To read. The meaning of 'DosyaOku' is FileRead. 'Randevu' means appointment in Turkish.
		ofstream GeciciDosyaYaz("Appointment.tmp");  //To write The meaning of 'DosyaYaz' is FileWrite. 'Gecici' means temporary in Turkish.

		while (RandevuDosyaOku >> PatientIdentityNumber >> AppointmentDate >> AppointmentHour >> DoctorName >> Test >> Diagnosis >> Medication)
		{
			if (UpdatingIdentityNo != PatientIdentityNumber)
				GeciciDosyaYaz << "\n" << PatientIdentityNumber << " " << AppointmentDate << " " << AppointmentHour << " " << DoctorName << " " << Test << " " << Diagnosis << " " << Medication << endl;

			if (UpdatingIdentityNo == PatientIdentityNumber)
			{
				cout << "   Please, Enter the Updated Appointment Informations" << endl;
				cout << "   Enter the Appointment Date: "; cin >> AppointmentDate;
				cout << "   Enter the Appointment Hour: "; cin >> AppointmentHour;
				cout << "   Enter the Doctor Name: "; cin >> DoctorName;

				GeciciDosyaYaz << "\n" << PatientIdentityNumber << " " << AppointmentDate << " " << AppointmentHour << " " << DoctorName << " " << "-" << " " << "-" << " " << "-" << endl;
				// The given appointment information were written.
				gcc = 1;
			}
		}
		GeciciDosyaYaz.close();
		RandevuDosyaOku.close();

		remove("Appointment.txt"); //Appointment.txt file was delete.
		rename("Appointment.tmp", "Appointment.txt"); //Appointment.tmp file was copied to Appointment.txt

		if (gcc == 0)
			cout << "   There is no appointment according to the given information." << endl;
		if (gcc == 1)
			cout << "   The appointment is updated. Get well soon." << endl;

	}

	if (selection == 6)
	{
		system("cls"); 
		cout << "6. Deleting Appointment" << endl;

		int gcc = 0;
		int decision = 0;
		
		cout << "   Please, Enter the Identity Number to be deleted: "; 
		cin >> DeletedIdentityNo; 

		ifstream DosyaOku("Patient.txt");

		while (!DosyaOku.eof())
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;

			if (PatientIdentityNumber == DeletedIdentityNo)
			{
				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

				cout << "   Patient Identity Number: " << DeletedIdentityNo << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;

			}

				cout << "Would you like to delete the appointment? [(Y)es/(N)o]: ";
				cin >> decision;

			if (decision == 'y')
			{
				ifstream RandevuDosyaOku("Appointment.txt"); 
				ofstream GeciciDosyaYaz("Appointment.tmp");

				while (RandevuDosyaOku >> PatientIdentityNumber >> AppointmentDate >> AppointmentHour >> DoctorName >> Test >> Diagnosis >> Medication)
				{

					if (DeletedIdentityNo != PatientIdentityNumber)
						GeciciDosyaYaz << PatientIdentityNumber << " " << AppointmentDate << " " << AppointmentHour << " " << DoctorName << " " << Test << " " << Diagnosis << " " << Medication << endl;

					if (DeletedIdentityNo == PatientIdentityNumber)
						gcc = 1;
				}

				GeciciDosyaYaz.close();
				DosyaOku.close();
				RandevuDosyaOku.close();

				remove("Appointment.txt"); //Appointment.txt file was deleted.
				rename("Appointment.tmp", "Appointment.txt"); //Appointment.tmp file was copied to Appointment.txt

				if (gcc == 0)
					cout << "   There is no appointment." << endl;
				if (gcc == 1)
					cout << "   The appointment is deleted." << endl;
			}
			else
				break;
		}
	}
	
	if (selection == 7)
	{
		system("cls");
		cout << "7. Examination Record of the Patient" << endl;
		
		ifstream DosyaOku("Patient.txt");

		cout << "   Please, Enter the Identity Number to be examinated patient: "; 
		cin >> ExaminatedIdentityNo;
		
		int gcc = 0;

		while (!(DosyaOku.eof())) 
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;

			if (PatientIdentityNumber == ExaminatedIdentityNo)
			{
				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

				cout << "   Patient Identity Number: " << ExaminatedIdentityNo << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;

				DosyaOku.close();

				ifstream DosyaOku("Appointment.txt");
				ofstream DosyaYaz("Appointment.txt", ios::app);

				while (!(DosyaOku.eof())) 
				{
					DosyaOku >> PatientIdentityNumber >> AppointmentDate >> AppointmentHour >> DoctorName >> Test >> Diagnosis >> Medication;
					if (ExaminatedIdentityNo == PatientIdentityNumber)
					{
						do
						{
							cout << "   APPOINTMENT INFORMATIONS" << endl;

							cout << "   Identity Number: " << ExaminatedIdentityNo << endl;
							cout << "   Appointment Date:" << AppointmentDate << endl;
							cout << "   Appointment Hour:" << AppointmentHour << endl;
							cout << "   Doctor Name:" << DoctorName << endl;

							cout << "   Please, Enter the Required Test: "; cin >> Test;
							cout << "   Please, Enter the Acquired Diagnosis: "; cin >> Diagnosis;
							cout << "   Please, Enter the Required Medications: "; cin >> Medication;

							DosyaYaz << "\n" << PatientIdentityNumber << " " << Test << " " << Diagnosis << " " << Medication << endl;

							cout << "   Examination Record is completed." << endl;
							cout << "   Would you like to continue to do Examination Record? [(Y)es/(N)o]: "; 
							cin >> answer;
							cout << endl;
						} while (!(answer == 'n')); //Continue to record untill the answer is "No".
					}
				}

				DosyaYaz.close(); 

				gcc = 1;
				break;
			}
			if (gcc == 0)
				cout << "   There is no recording according to the given informations." << endl;
		}
	}

	if (selection == 8)
	{
		system("cls"); 
		
		cout << "8. Take the Patient List" << endl << endl;
		
		ifstream DosyaOku("Patient.txt");
		
		while (!(DosyaOku.eof())) 
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;
			
			cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

			cout << "   Patient Identity Number: " << PatientIdentityNumber << endl;
			cout << "   Patient Name: " << PatientName << endl;
			cout << "   Patient Surname: " << PatientSurname << endl;
			cout << "   Patient Regist Number: " << PatientRegistNo << endl;
			cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
			cout << "   Patient Birthday: " << PatientBirthday << endl;
			cout << "   Patient Gender: " << PatientGender << endl << endl;
		}
		DosyaOku.close(); 
	}
	
	if (selection == 9)
	{
		system("cls");
	
		cout << "9. Investigation the Patient " << endl;
		
		cout << "   Please, Enter the Identity Number that is want to be examinated: "; 
		cin >> ExaminatedIdentityNo;

		int gcc1 = 0, gcc2 = 0;
		ifstream DosyaOku("Patient.txt");
		while (!(DosyaOku.eof()))
		{
			DosyaOku >> PatientIdentityNumber >> PatientName >> PatientSurname >> PatientRegistNo >> PatientPhoneNumber >> PatientBirthday >> PatientGender;

			if (ExaminatedIdentityNo == PatientIdentityNumber)
			{
				cout << "   PERSONAL PATIENT INFORMATIONS" << endl << endl;

				cout << "   Patient Identity Number: " << ExaminatedIdentityNo << endl;
				cout << "   Patient Name: " << PatientName << endl;
				cout << "   Patient Surname: " << PatientSurname << endl;
				cout << "   Patient Regist Number: " << PatientRegistNo << endl;
				cout << "   Patient Phone Number: " << PatientPhoneNumber << endl;
				cout << "   Patient Birthday: " << PatientBirthday << endl;
				cout << "   Patient Gender: " << PatientGender << endl << endl;

				DosyaOku.close();

				gcc1 = 1;
				break;
			}
		}

		ifstream DosyaOku2("Appointment.txt"); 

		while (!(DosyaOku2.eof()))
		{
			DosyaOku2 >> PatientIdentityNumber >> AppointmentDate >> AppointmentHour >> DoctorName >> Test >> Diagnosis >> Medication;

			if (ExaminatedIdentityNo == PatientIdentityNumber)
			{
				cout << "   APPOINTMENT INFORMATIONS" << endl;

				cout << "   Identity Number: " << PatientIdentityNumber << endl;
				cout << "   Appointment Date: " << AppointmentDate << endl;
				cout << "   Appointment Hour: " << AppointmentHour << endl;
				cout << "   Doctor Name: " << DoctorName << endl;
				cout << "   Test Results: " << Test << endl;
				cout << "   Acquired Diagnosis: " << Diagnosis << endl;
				cout << "   Medications to be used: " << Medication << endl;

				gcc2 = 1; //If the file reading is ended, gcc variable is 1.
				PatientIdentityNumber += 1; //The value of PatientIdentityNumber was changed in order to preventing the repeating the loop ath the end.
			}
		}
		DosyaOku2.close();
		if (gcc1 == 0) //If there was no file reading, the value of gcc is gonna be zero and the error is gonna be given on the screen.
			cout << "   There is no Patient Recorging according to the given information." << endl;
		if (gcc2 == 0)
			cout << "   There is no appointment recording according to the given information." << endl;
	}
	
	system("pause");
	return 0; //Close the program..
}

	// This code was written Fall 2017 as course project. Please feel free to contact to me if further information is needed.
	// King regards. 