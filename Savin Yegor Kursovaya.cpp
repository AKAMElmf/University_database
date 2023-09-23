#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
void dataInitialization();
void dataSet();
bool dataCleaning();
int AmountOfData();
void dataSave();
void dataAdd();
void dataDelete();
bool FileIsExist(string filePath);
void Copy();
void dataChange();
bool fileVoid(string filename);
void dataReading();
void Print();
void space(string predm, int n);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	dataInitialization();
	int meniu = 8;
	while (1)
	{
		if ((1 <= meniu && meniu <= 8))
		{
			if (meniu == 1)
			{
				int action;
				system("cls");
				cout << "Ввод вручную или из файла?\n1.Вручную 2.Из файла\n" << endl;
				cin >> action;
				if (action == 1)
				{
					dataSet();
				}
				else if (action == 2)
				{
					dataReading();
				}
				else
				{
					while (action > 2 || action < 1)
					{
						cout << "Ошибка ввода!\n";
						cin >> action;
					}
					if (action == 1)
					{
						dataSet();
					}
					else if (action == 2)
					{
						dataReading();
					}
				}
				meniu = 8;
			}
			if (meniu == 2)
			{
				dataAdd();
				meniu = 8;
			}
			if (meniu == 6)
			{
				dataSave();
				meniu = 8;
			}
			if (meniu == 4)
			{
				dataDelete();
				meniu = 8;
			}
			if (meniu == 3)
			{
				dataChange();
				meniu = 8;
			}
			if (meniu == 5)
			{
				Print();
				system("pause");
				meniu = 8;
			}
			if (meniu == 8)
			{
				system("cls");
				cout << " МЕНЮ:\n";
				cout << "  1.Ввод/загрузка\n";
				cout << "  2.Добавление данных\n";
				cout << "  3.Изменение данных\n";
				cout << "  4.Удаление данных\n";
				cout << "  5.Вывод\n";
				cout << "  6.Сохранение\n";   
				cout << "  7.Выход\n\n";
			}
			if (meniu == 7)
			{
				system("cls");
				if (dataCleaning())
					cout << "Данные из буфера очищеный!" << endl;
				else
					cout << "Данные из буфера НЕ очищены!!!" << endl;
				cout << "Работа завершена." << endl;
				break;
			}
		}
		else
		{
			cout << "Ошибка ввода! \n\n";
				return 0;
		}
		cout << "Меню: ";
		cin >> meniu;
	}
	system("pause");
	return 0;
}
void dataSet()
{
	system("cls");
	if (!fileVoid("Buffer.txt"))
	{
		int a;
		cout << "База данных уже загружена!" << endl;
		cout << "1.Ввести другую БД 2.Выйти" << endl;
		cin >> a;
		if (a == 1)
		{
			fstream file("Buffer.txt", ios::out);
			file.clear();
			file.close();
			system("cls");
		}
		else if (a == 2)
		{
			return void();
		}
		else
		{
			while (a > 2 || a < 1)
			{
				cout << "Ошибка ввода!";
				cin >> a;
			}
			if (a == 2)
				return void();
			else
			{
				fstream file("Buffer.txt", ios::out);
				file.clear();
				file.close();
				system("cls");
			}
		}
	}
	int n;
	cout << "Введите колличество институтов: ";
	cin >> n;
	ofstream record("Buffer.txt", ios::app);
	if (record)
	{
		if (n==0)
			record << n;
		else
			record << n << endl;
		for (int i = 0; i < n; i++)
		{
			if (i < n - 1)
			{
				string inst;
				cout << "Введите название института: ";
				while (cin.get() != '\n');
				getline(cin, inst);
				record << inst << endl;
				int m;
				cout << "Сколько кафедр в этом институте? ";
				cin >> m;
				record << m << endl;
				for (int i = 0; i < m; i++)
				{
					int m;
					string kaf;
					cout << "Введите название кафедры: ";
					while (cin.get() != '\n');
					getline(cin, kaf);
					record << kaf << endl;
					cout << "Сколько групп в этой кафедре? ";
					cin >> m;
					record << m << endl;
					for (int i = 0; i < m; i++)
					{
						int a;
						int m;
						string grupp;
						cout << "Введите название группы: ";
						while (cin.get() != '\n');
						getline(cin, grupp);
						record << grupp << endl;
						cout << "Сколько студентов в этой группе? ";
						cin >> m;
						cout << "Введите колличество предметов у студентов этой группы: ";
						cin >> a;
						if (a == 0)
						{
							cout << "Ошибка ввода!";
							system("pause");
							record.clear();
							record.close();
							return void();
						}
						int* kurs = new int[a];
						string* predm = new string[a];
						record << m << endl;
						record << a << endl;
						for (int i = 0; i < a; i++)
						{
							int a;
							string pred;
							cout << "Введите название предмета: ";
							while (cin.get() != '\n');
							getline(cin, pred);
							predm[i] = pred;
							cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
							cin >> a;
							a--;
							kurs[i] = a;
						}
						for (int i = 0; i < m; i++)
						{
							string fio;
							cout << "Введите ФИО студента: ";
							while (cin.get() != '\n');
							getline(cin, fio);
							record << fio << endl;
							for (int i = 0; i < a; i++)
							{
								int ocen;
								cout << "Оценка по предмету " << predm[i] << ": ";
								record << predm[i] << endl;
								cin >> ocen;
								record << ocen << endl;
								if (kurs[i] == 0)
								{
									int ocen;
									cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
									cin >> ocen;
									record << ocen << endl;
								}
								else
								{
									record << 0 << endl;
								}
							}
						}
						delete[] predm;
						delete[] kurs;
					}
				}
				cout << "_________________________________________________________________________________\n";
				cout << "\nВы успешно доабивили данные по институту!" << endl;
				system("Pause");
				system("cls");
			}
			else
			{
			string inst;
			cout << "Введите название института: ";
			while (cin.get() != '\n');
			getline(cin, inst);
			record << inst << endl;
			int m;
			cout << "Сколько кафедр в этом институте? ";
			cin >> m;
			if (m == 0)
				record << m;
			else
				record << m << endl;
			for (int i = 0; i < m; i++)
			{
				if (i < m - 1)
				{
					int m;
					string kaf;
					cout << "Введите название кафедры: ";
					while (cin.get() != '\n');
					getline(cin, kaf);
					record << kaf << endl;
					cout << "Сколько групп в этой кафедре? ";
					cin >> m;
					record << m << endl;
					for (int i = 0; i < m; i++)
					{
						int a;
						int m;
						string grupp;
						cout << "Введите название группы: ";
						while (cin.get() != '\n');
						getline(cin, grupp);
						record << grupp << endl;
						cout << "Сколько студентов в этой группе? ";
						cin >> m;
						cout << "Введите колличество предметов у студентов этой группы: ";
						cin >> a;
						if (a == 0)
						{
							cout << "Ошибка ввода!";
							system("pause");
							record.clear();
							record.close();
							return void();
						}
						int* kurs = new int[a];
						string* predm = new string[a];
						record << m << endl;
						record << a << endl;
						for (int i = 0; i < a; i++)
						{
							int a;
							string pred;
							cout << "Введите название предметов: ";
							while (cin.get() != '\n');
							getline(cin, pred);
							predm[i] = pred;
							cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
							cin >> a;
							a--;
							kurs[i] = a;
						}
						for (int i = 0; i < m; i++)
						{
							string fio;
							cout << "Введите ФИО студента: ";
							while (cin.get() != '\n');
							getline(cin, fio);
							record << fio << endl;
							for (int i = 0; i < a; i++)
							{
								int ocen;
								cout << "Оценка по предмету " << predm[i] << ": ";
								record << predm[i] << endl;
								cin >> ocen;
								record << ocen << endl;
								if (kurs[i] == 0)
								{
									int ocen;
									cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
									cin >> ocen;
									record << ocen << endl;
								}
								else
								{
									record << 0 << endl;
								}
							}
						}
						delete[] predm;
						delete[] kurs;
					}
				}
				else
				{
					int m;
					string kaf;
					cout << "Введите название кафедры: ";
					while (cin.get() != '\n');
					getline(cin, kaf);
					record << kaf << endl;
					cout << "Сколько групп в этой кафедре? ";
					cin >> m;
					if (m == 0)
						record << m;
					else
						record << m << endl;
					for (int i = 0; i < m; i++)
					{
						if (i < m - 1)
						{
							int a;
							int m;
							string grupp;
							cout << "Введите название группы: ";
							while (cin.get() != '\n');
							getline(cin, grupp);
							record << grupp << endl;
							cout << "Сколько студентов в этой группе? ";
							cin >> m;
							cout << "Введите колличество предметов у студентов этой группы: ";
							cin >> a;
							if (a == 0)
							{
								cout << "Ошибка ввода!";
								system("pause");
								record.clear();
								record.close();
								return void();
							}
							int* kurs = new int[a];
							string* predm = new string[a];
							record << m << endl;
							record << a << endl;
							for (int i = 0; i < a; i++)
							{
								int a;
								string pred;
								cout << "Введите название предметов: ";
								while (cin.get() != '\n');
								getline(cin, pred);
								predm[i] = pred;
								cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
								cin >> a;
								a--;
								kurs[i] = a;
							}
							for (int i = 0; i < m; i++)
							{
								string fio;
								cout << "Введите ФИО студента: ";
								while (cin.get() != '\n');
								getline(cin, fio);
								record << fio << endl;
								for (int i = 0; i < a; i++)
								{
									int ocen;
									cout << "Оценка по предмету " << predm[i] << ": ";
									record << predm[i] << endl;
									cin >> ocen;
									record << ocen << endl;
									if (kurs[i] == 0)
									{
										int ocen;
										cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
										cin >> ocen;
										record << ocen << endl;
									}
									else
									{
										record << 0 << endl;
									}
								}
							}
							delete[] predm;
							delete[] kurs;
						}
						else
						{
							int a;
							int m;
							string grupp;
							cout << "Введите название группы: ";
							while (cin.get() != '\n');
							getline(cin, grupp);
							record << grupp << endl;
							cout << "Сколько студентов в этой группе? ";
							cin >> m;
							cout << "Введите колличество предметов у студентов этой группы: ";
							cin >> a;
							if (a == 0)
							{
								cout << "Ошибка ввода!";
								system("pause");
								record.clear();
								record.close();
								return void();
							}
							int* kurs = new int[a];
							string* predm = new string[a];
							if (m == 0)
							{
								record << m<<endl;
								record << a;
							}
							else
							{
								record << m << endl;
								record << a << endl;
							}
							for (int i = 0; i < a; i++)
							{
								int a;
								string pred;
								cout << "Введите название предметов: ";
								while (cin.get() != '\n');
								getline(cin, pred);
								predm[i] = pred;
								cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
								cin >> a;
								a--;
								kurs[i] = a;
							}
							for (int i = 0; i < m; i++)
							{
								if (i < m - 1)
								{
									string fio;
									cout << "Введите ФИО студента: ";
									while (cin.get() != '\n');
									getline(cin, fio);
									record << fio << endl;
									for (int i = 0; i < a; i++)
									{
										int ocen;
										cout << "Оценка по предмету " << predm[i] << ": ";
										record << predm[i] << endl;
										cin >> ocen;
										record << ocen << endl;
										if (kurs[i] == 0)
										{
											int ocen;
											cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
											cin >> ocen;
											record << ocen << endl;
										}
										else
										{
											record << 0 << endl;
										}
									}
								}
								else
								{
									string fio;
									cout << "Введите ФИО студента: ";
									while (cin.get() != '\n');
									getline(cin, fio);
									record << fio << endl;
									for (int i = 0; i < a; i++)
									{
										if (i < a - 1)
										{
											int ocen;
											cout << "Оценка по предмету " << predm[i] << ": ";
											record << predm[i] << endl;
											cin >> ocen;
											record << ocen << endl;
											if (kurs[i] == 0)
											{
												int ocen;
												cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
												cin >> ocen;
												record << ocen << endl;
											}
											else
											{
												record << 0 << endl;
											}
										}
										else
										{
											int ocen;
											cout << "Оценка по предмету " << predm[i] << ": ";
											record << predm[i] << endl;
											cin >> ocen;
											record << ocen << endl;
											if (kurs[i] == 0)
											{
												int ocen;
												cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
												cin >> ocen;
												record << ocen;
											}
											else
											{
												record << 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout << "_________________________________________________________________________________\n";
			cout << "\nВы успешно доабивили данные по институту!" << endl;
			system("Pause");
			system("cls");
			}
		}
		cout << "Вы успешно создали БД!" << endl;
		system("Pause");
		record.close();
	}
	else
	{
		cout << "Ошибка открытия файла!" << endl;
		system("pause");
	}
}
void Print()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "Буфер пуст!" << endl;
		return void();
	}
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string nazv;
		int p;
		reading >> p;
		reading.ignore();
		cout << " -----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| Количество институтов: " << p <<"                                                                                        |"<< endl;
		cout << " -----------------------------------------------------------------------------------------------------------------\n" << endl;
		for (int i = 0; i < p; i++)
		{
			cout << "__________________________________________________________________________________________________________________________________" << endl;
			int n;
			cout << "Данные о институте №" << i + 1 << endl;
			getline(reading, nazv);
			cout << "Название института: " <<  nazv << endl;
			reading >> n;
			reading.ignore();
			cout << "Количетсво кафедр в институте " << nazv << ": "<<n<<endl;
			for (int i = 0; i < n; i++)
			{
				cout << "\t=========================================================================================================================" << endl;
				int l;
				cout << "\tДанные о кафедре №" << i + 1 << endl;
				getline(reading, nazv);
				cout << "\tНазвание кафедры: " << nazv << endl;
				reading >> l;
				reading.ignore();
				cout << "\tКоличетсво групп в кафедре " << nazv << ": " << l << endl;
				for (int i = 0; i < l; i++)
				{
					int k;
					int m;
					cout << "\t\t----------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t\tДанные о группе №" << i + 1 << endl;
					getline(reading, nazv);
					cout << "\t\tНазвание группы: " << nazv << endl;
					reading >> k;
					cout << "\t\tКоличетсво студентов в группе " << nazv << ": " << k << endl<<endl;
					reading >> m;
					reading.ignore();
					for (int i = 0; i < k; i++)
					{
						cout << "\t\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
						cout << "\t\t\t+ Данные о студенте №" << i + 1;
						if (i>9)
							cout<< "                                                                                 +" << endl;
						else
							cout<< "                                                                                +" << endl;
						getline(reading, nazv);
						cout << "\t\t\t+  Имя студента: " << nazv;
						space(nazv, 85);
						cout << "+" << endl;
						cout << "\t\t\t+  Оценки студента " << "                                                                                   +" << endl;
						for (int i = 0; i < m; i++)
						{
							int ocen;
							getline(reading, nazv);
							reading >> ocen;
							cout <<"\t\t\t+  "<< nazv << ": " << ocen;
							reading >> ocen;
							reading.ignore();
							if (ocen == 0)
							{
								space(nazv,45);
								cout << "|  "  << "\tУ этого предмета нет курсовой работы          +" << endl;
							}
							else
							{
								space(nazv,45);
								cout << "|  " << "\tОценка за курсовую работу по этому предмету:" << ocen <<" +"<<endl;
							}
						}
						if (i+1==k)
						cout << "\t\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
					}
					if (i + 1 == l)
					cout << "\t\t----------------------------------------------------------------------------------------------------------------" << endl;
				}
				if (i + 1 == n)
				cout << "\t=========================================================================================================================" << endl;
			}
			if (i + 1 == p)
			cout << "__________________________________________________________________________________________________________________________________\n";
		}
	}
	else
	{
		cout << "Ошибка открытия файла!" << endl;
		system("pause");
	}
	reading.close();
}
void space(string predm, int n)
{
	int b = n - predm.size();
	for (int i = 0; i < b; i++)
		cout << " ";
}
void dataChange()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "Буфер пуст!" << endl;
		system("pause");
		return void(); 
	}
	if (AmountOfData() == 0)
	{
		cout << "Данных для изменения больше нет!" << endl;
		system("pause");
		return void();
	}
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string nazv;
		int ocen;
		int n;
		reading >> n;
		reading.ignore();
		for (int i = 0; i < n; i++)
		{
			int n;
			getline(reading, nazv);
			cout << i + 1 << "." << nazv << " ";
			reading >> n;
			reading.ignore();
			for (int i = 0; i < n; i++)
			{
				int n;
				getline(reading, nazv);
				reading >> n;
				reading.ignore();
				for (int i = 0; i < n; i++)
				{
					int n;
					int m;
					getline(reading, nazv);
					reading >> n;
					reading >> m;
					reading.ignore();
					for (int i = 0; i < n; i++)
					{
						getline(reading, nazv);
						for (int i = 0; i < m; i++)
						{
							getline(reading, nazv);
							reading >> ocen;
							reading >> ocen;
							reading.ignore();
						}
					}
				}
			}
		}
		int a;
		cout << "\n1.Изменить 2.Далее\n";
		cin >> a;
		if (a == 1)
		{
			reading.close();
			Copy();
			ifstream reading("Buffer_.txt");
			ofstream record("Buffer.txt", ios::out);
			if (reading)
			{
				if (record)
				{
					string nazv;
					int ocen;
					int n;
					reading >> n;
					reading.ignore();
					int _n;
					cout << "Выберите номер элемента, который хотите изменить: ";
					cin >> _n;
					_n--;
					system("cls");
					record << n << endl;
					if (_n >= 0 && _n < n)
					{
						for (int i = 0; i < n; i++)
						{
							if (i != _n)
							{
								if (i < n - 1)
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int i = 0; i < n; i++)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
									}
								}
								else
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int i = 0; i < n; i++)
									{
										if (i < n - 1)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int i = 0; i < n; i++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
										}
										else
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if (n == 0)
												record << n;
											else
												record << n << endl;
											for (int i = 0; i < n; i++)
											{
												if (i < n - 1)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if (n == 0)
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int i = 0; i < n; i++)
													{
														if (i < n - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
							else
							{
								cout << "Введите новое название института" << endl;
								if (i < n - 1)
								{
									int n;
									while (cin.get() != '\n');
									getline(cin, nazv);
									record << nazv << endl;
									getline(reading, nazv);
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int i = 0; i < n; i++)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
									}
								}
								else
								{
									int n;
									while (cin.get() != '\n');
									getline(cin, nazv);
									record << nazv << endl;
									getline(reading, nazv);
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int i = 0; i < n; i++)
									{
										if (i < n - 1)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int i = 0; i < n; i++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
										}
										else
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if (n == 0)
												record << n;
											else
												record << n << endl;
											for (int i = 0; i < n; i++)
											{
												if (i < n - 1)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if (n == 0)
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int i = 0; i < n; i++)
													{
														if (i < n - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
						cout << "Вы успешно изменили данные!" << endl;
						system("pause");
					}
					else
					{
						cout << "Элемента с таким номером не существует!" << endl;
						system("Pause");
						return void();
					}
					reading.close();
					record.close();
					remove("Buffer_.txt");
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
			}
			else
			{
				cout << "Ошибка открытия буферного файла!\n";
				system("Pause");
			}
		}
		else if (a == 2)
		{
			int b=-1;
			reading.close();
			ifstream reading("Buffer.txt");
			if (reading)
			{
				cout << "Выберите номер института: ";
				cin >> b;
				system("cls");
				string nazv;
				int ocen;
				int n;
				reading >> n;
				reading.ignore();
				for (int j = 0; j < n; j++)
				{
					int n;
					getline(reading, nazv);
					reading >> n;
					if ((n == 0) && (j+1==b))
					{
						cout << "Данных для изменения больше нет!" << endl;
						system("pause");
						reading.close();
						return void();
					}
					reading.ignore();
					for (int i = 0; i < n; i++)
					{
						int n;
						getline(reading, nazv);
						if (j + 1 == b)
							cout << i + 1 << "." << nazv << " ";
						reading >> n;
						reading.ignore();
						for (int i = 0; i < n; i++)
						{
							int n;
							int m;
							getline(reading, nazv);
							reading >> n;
							reading >> m;
							reading.ignore();
							for (int i = 0; i < n; i++)
							{
								getline(reading, nazv);
								for (int i = 0; i < m; i++)
								{
									getline(reading, nazv);
									reading >> ocen;
									reading >> ocen;
									reading.ignore();
								}
							}
						}
					}
				}
			}
			else
			{
				cout << "Ошибка открытия буферного файла!\n";
				system("Pause");
			}
			cout << "\n1.Изменить 2.Далее\n";
			cin >> a;
			if (a == 1)
			{
				reading.close();
				Copy();
				ifstream reading("Buffer_.txt");
				ofstream record("Buffer.txt", ios::out);
				if (reading)
				{
					if (record)
					{
						string nazv;
						int ocen;
						int n;
						reading >> n;
						reading.ignore();
						int c;
						cout << "Выберите номер элемента, который хотите изменить: ";
						cin >> c;
						system("cls");
						record << n << endl;
						for (int j = 0; j < n; j++)
						{
							if (j < n - 1)
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								reading.ignore();
								record << n << endl;
								for (int r = 0; r < n; r++)
								{
									int n;
									if ((j + 1 == b) && (r + 1 == c))
									{
										cout << "Введите новое название кафедры: ";
										while (cin.get() != '\n');
										getline(cin, nazv);
										record << nazv << endl;
										getline(reading, nazv);
									}
									else
									{
										getline(reading, nazv);
										record << nazv << endl;
									}
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int i = 0; i < n; i++)
									{
										int n;
										int m;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m << endl;
										for (int i = 0; i < n; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												reading >> ocen;
												record << ocen << endl;
												reading >> ocen;
												reading.ignore();
												record << ocen << endl;
											}
										}
									}
								}
							}
							else
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								reading.ignore();
								if (n == 0)
									record << n;
								else
									record << n << endl;
								for (int r = 0; r < n; r++)
								{
									if (r < n - 1)
									{
										int n;
										if ((j + 1 == b) && (r + 1 == c))
										{
											cout << "Введите новое название кафедры: ";
											while (cin.get() != '\n');
											getline(cin, nazv);
											record << nazv << endl;
											getline(reading, nazv);
										}
										else
										{
											getline(reading, nazv);
											record << nazv << endl;
										}
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
									}
									else
									{
										int n;
										if ((j + 1 == b) && (r + 1 == c))
										{
											cout << "Введите новое название кафедры: ";
											while (cin.get() != '\n');
											getline(cin, nazv);
											record << nazv << endl;
											getline(reading, nazv);
										}
										else
										{
											getline(reading, nazv);
											record << nazv << endl;
										}
										reading >> n;
										reading.ignore();
										if (n == 0)
											record << n;
										else
											record << n << endl;
										for (int i = 0; i < n; i++)
										{
											if (i < n - 1)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
											else
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												if (n == 0)
												{
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m;
												}
												else
												{
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
												}
												for (int i = 0; i < n; i++)
												{
													if (i < n - 1)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
													else
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															if (i < m - 1)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
															else
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
						cout << "Вы успешно изменили данные!" << endl;
						system("pause");
						reading.close();
						record.close();
						remove("Buffer_.txt");
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
			}
			else if (a == 2)
			{
				int c=-1;
				reading.close();
				ifstream reading("Buffer.txt");
				if (reading)
				{
					cout << "Выберите номер кафедры: ";
					cin >> c;
					system("cls");
					string nazv;
					int ocen;
					int n;
					reading >> n;
					reading.ignore();
					for (int j = 0; j < n; j++)
					{
						int n;
						getline(reading, nazv);
						reading >> n;
						reading.ignore();
						for (int r = 0; r < n; r++)
						{
							int n;
							getline(reading, nazv);
							reading >> n;
							if ((n == 0) && (j + 1 == b) && (r + 1==c))
							{
								cout << "Данных для изменения больше нет!" << endl;
								system("pause");
								reading.close();
								return void();
							}
							reading.ignore();
							for (int i = 0; i < n; i++)
							{
								int n;
								int m;
								getline(reading, nazv);
								if ((j + 1 == b) && (r + 1 == c))
									cout << i + 1 << "." << nazv << " ";
								reading >> n;
								reading >> m;
								reading.ignore();
								for (int i = 0; i < n; i++)
								{
									getline(reading, nazv);
									for (int i = 0; i < m; i++)
									{
										getline(reading, nazv);
										reading >> ocen;
										reading >> ocen;
										reading.ignore();
									}
								}
							}
						}
					}
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
				cout << "\n1.Изменить 2.Далее\n";
				cin >> a;
				if (a == 1)
				{
					reading.close();
					Copy();
					ifstream reading("Buffer_.txt");
					ofstream record("Buffer.txt", ios::out);
					if (reading)
					{
						if (record)
						{
							string nazv;
							int ocen;
							int n;
							reading >> n;
							reading.ignore();
							int d;
							cout << "Выберите номер элемента, который хотите изменить: ";
							cin >> d;
							system("cls");
							record << n << endl;
							for (int j = 0; j < n; j++)
							{
								if (j < n - 1)
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int r = 0; r < n; r++)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int p = 0; p < n; p++)
										{
											int n;
											int m;
											if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
											{
												cout << "Введите новое название группы: ";
												while (cin.get() != '\n');
												getline(cin, nazv);
												record << nazv << endl;
												getline(reading, nazv);
											}
											else
											{
												getline(reading, nazv);
												record << nazv << endl;
											}
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
									}
								}
								else
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int r = 0; r < n; r++)
									{
										if (r < n - 1)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int p = 0; p < n; p++)
											{
												int n;
												int m;
												if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
												{
													cout << "Введите новое название группы: ";
													while (cin.get() != '\n');
													getline(cin, nazv);
													record << nazv << endl;
													getline(reading, nazv);
												}
												else
												{
													getline(reading, nazv);
													record << nazv << endl;
												}
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
										}
										else
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if (n == 0)
												record << n;
											else
												record << n << endl;
											for (int p = 0; p < n; p++)
											{
												if (p < n - 1)
												{
													int n;
													int m;
													if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
													{
														cout << "Введите новое название группы: ";
														while (cin.get() != '\n');
														getline(cin, nazv);
														record << nazv << endl;
														getline(reading, nazv);
													}
													else
													{
														getline(reading, nazv);
														record << nazv << endl;
													}
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
													{
														cout << "Введите новое название группы: ";
														while (cin.get() != '\n');
														getline(cin, nazv);
														record << nazv << endl;
														getline(reading, nazv);
													}
													else
													{
														getline(reading, nazv);
														record << nazv << endl;
													}
													reading >> n;
													if (n == 0)
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int i = 0; i < n; i++)
													{
														if (i < n - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
							cout << "Вы успешно изменили данные!" << endl;
							system("pause");
							reading.close();
							record.close();
							remove("Buffer_.txt");
						}
						else
						{
							cout << "Ошибка открытия буферного файла!\n";
							system("Pause");
						}
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
				}
				else if (a == 2)
				{
					int d=-1;
					reading.close();
					ifstream reading("Buffer.txt");
					if (reading)
					{
						cout << "Выберите номер группы: ";
						cin >> d;
						system("cls");
						string nazv;
						int ocen;
						int n;
						reading >> n;
						reading.ignore();
						for (int j = 0; j < n; j++)
						{
							int n;
							getline(reading, nazv);
							reading >> n;
							reading.ignore();
							for (int r = 0; r < n; r++)
							{
								int n;
								getline(reading, nazv);
								reading >> n;
								reading.ignore();
								for (int p = 0; p < n; p++)
								{
									int n;
									int m;
									getline(reading, nazv);
									reading >> n;
									if ((n == 0) && (j + 1 == b) && (r + 1 == c) && (p + 1 == d))
									{
										cout << "Данных для изменения больше нет!" << endl;
										system("pause");
										reading.close();
										return void();
									}
									reading >> m;
									reading.ignore();
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
											cout << i + 1 << "." << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											reading >> ocen;
											reading >> ocen;
											reading.ignore();
										}
									}
								}
							}
						}
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
					cout << "\n1.Изменить 2.Выйти\n";
					cin >> a;
					if (a == 1)
					{
						reading.close();
						Copy();
						ifstream reading("Buffer_.txt");
						ofstream record("Buffer.txt", ios::out);
						if (reading)
						{
							if (record)
							{
								string nazv;
								int ocen;
								int n;
								reading >> n;
								reading.ignore();
								int e;
								cout << "Выберите номер элемента, который хотите изменить: ";
								cin >> e;
								system("cls");
								record << n << endl;
								for (int j = 0; j < n; j++)
								{
									if (j < n - 1)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int r = 0; r < n; r++)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int p = 0; p < n; p++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int o = 0; o < n; o++)
												{
													if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == e))
													{
														cout << "Введите новое ФИО студента: ";
														while (cin.get() != '\n');
														getline(cin, nazv);
														record << nazv << endl;
														getline(reading, nazv);
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															cout << "Оценка по предмету " << nazv << ": ";
															cin >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading >> ocen;
															reading.ignore();
															if (ocen != 0)
															{
																cout << "Оценка за курсовую по предмету " << nazv << ": ";
																cin >> ocen;
																record << ocen << endl;
															}
															else
															{
																record << 0 << endl;
															}
														}
													}
													else
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										if (n == 0)
											record << n;
										else
											record << n << endl;
										for (int r = 0; r < n; r++)
										{
											if (r < n - 1)
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												record << n << endl;
												for (int p = 0; p < n; p++)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int o = 0; o < n; o++)
													{
														if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == e))
														{
															cout << "Введите новое ФИО студента: ";
															while (cin.get() != '\n');
															getline(cin, nazv);
															record << nazv << endl;
															getline(reading, nazv);
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																cout << "Оценка по предмету " << nazv << ": ";
																cin >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading >> ocen;
																reading.ignore();
																if (ocen != 0)
																{
																	cout << "Оценка за курсовую по предмету " << nazv << ": ";
																	cin >> ocen;
																	record << ocen << endl;
																}
																else
																{
																	record << 0 << endl;
																}
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
													}
												}
											}
											else
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												if (n == 0)
													record << n;
												else
													record << n << endl;
												for (int p = 0; p < n; p++)
												{
													if (p < n - 1)
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
														for (int o = 0; o < n; o++)
														{
															if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == e))
															{
																cout << "Введите новое ФИО студента: ";
																while (cin.get() != '\n');
																getline(cin, nazv);
																record << nazv << endl;
																getline(reading, nazv);
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	cout << "Оценка по предмету " << nazv << ": ";
																	cin >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading >> ocen;
																	reading.ignore();
																	if (ocen != 0)
																	{
																		cout << "Оценка за курсовую по предмету " << nazv << ": ";
																		cin >> ocen;
																		record << ocen << endl;
																	}
																	else
																	{
																		record << 0 << endl;
																	}
																}
															}
															else
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
															}
														}
													}
													else
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if (n == 0)
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m;
														}
														else
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														for (int o = 0; o < n; o++)
														{
															if (o < n - 1)
															{
																if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == e))
																{
																	cout << "Введите новое ФИО студента: ";
																	while (cin.get() != '\n');
																	getline(cin, nazv);
																	record << nazv << endl;
																	getline(reading, nazv);
																	for (int i = 0; i < m; i++)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		cout << "Оценка по предмету " << nazv << ": ";
																		cin >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading >> ocen;
																		reading.ignore();
																		if (ocen != 0)
																		{
																			cout << "Оценка за курсовую по предмету " << nazv << ": ";
																			cin >> ocen;
																			record << ocen << endl;
																		}
																		else
																		{
																			record << 0 << endl;
																		}
																	}
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	for (int i = 0; i < m; i++)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen << endl;
																	}
																}
															}
															else
															{
																if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == e))
																{
																	cout << "Введите новое ФИО студента: ";
																	while (cin.get() != '\n');
																	getline(cin, nazv);
																	record << nazv << endl;
																	getline(reading, nazv);
																	for (int i = 0; i < m; i++)
																	{
																		if (i < m - 1)
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			cout << "Оценка по предмету " << nazv << ": ";
																			cin >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading >> ocen;
																			reading.ignore();
																			if (ocen != 0)
																			{
																				cout << "Оценка за курсовую по предмету " << nazv << ": ";
																				cin >> ocen;
																				record << ocen << endl;
																			}
																			else
																			{
																				record << 0 << endl;
																			}
																		}
																		else
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			cout << "Оценка по предмету " << nazv << ": ";
																			cin >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading >> ocen;
																			reading.ignore();
																			if (ocen != 0)
																			{
																				cout << "Оценка за курсовую по предмету " << nazv << ": ";
																				cin >> ocen;
																				record << ocen;
																			}
																			else
																			{
																				record << 0;
																			}
																		}
																	}
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	for (int i = 0; i < m; i++)
																	{
																		if (i < m - 1)
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen << endl;
																		}
																		else
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
								cout << "Вы успешно изменили данные!" << endl;
								system("pause");
								reading.close();
								record.close();
								remove("Buffer_.txt");
							}
							else
							{
								cout << "Ошибка открытия буферного файла!\n";
								system("Pause");
							}
						}
						else
						{
							cout << "Ошибка открытия буферного файла!\n";
							system("Pause");
						}
					}
					else if (a == 2)
					{
						return void();
					}
				}
				else
				{
					cout << "Ошибка ввода!" << endl;
					system("pause");
					return void();
				}
			}
			else
			{
			cout << "Ошибка ввода!" << endl;
			system("pause");
			return void();
			}
		}
		else
		{
		cout << "Ошибка ввода!" << endl;
		system("pause");
		return void();
		}
	}
	else
	{
		cout << "Ошибка открытия буферного файла!\n";
		system("Pause");
	}
}
void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string nazv;
			int ocen;
			int n;
			reading >> n;
			reading.ignore();
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				if (i < n - 1)
				{
					int n;
					getline(reading, nazv);
					record << nazv << endl;
					reading >> n;
					reading.ignore();
					record << n << endl;
					for (int i = 0; i < n; i++)
					{
						int n;
						getline(reading, nazv);
						record << nazv << endl;
						reading >> n;
						reading.ignore();
						record << n << endl;
						for (int i = 0; i < n; i++)
						{
							int n;
							int m;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							record << n << endl;
							reading >> m;
							reading.ignore();
							record << m << endl;
							for (int i = 0; i < n; i++)
							{
								getline(reading, nazv);
								record << nazv << endl;
								for (int i = 0; i < m; i++)
								{
									getline(reading, nazv);
									record << nazv << endl;
									reading >> ocen;
									record << ocen << endl;
									reading >> ocen;
									reading.ignore();
									record << ocen << endl;
								}
							}
						}
					}
				}
				else
				{
					int n;
					getline(reading, nazv);
					record << nazv << endl;
					reading >> n;
					reading.ignore();
					if (n == 0)
						record << n;
					else
						record << n << endl;
					for (int i = 0; i < n; i++)
					{
						if (i < n - 1)
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							record << n << endl;
							for (int i = 0; i < n; i++)
							{
								int n;
								int m;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								record << n << endl;
								reading >> m;
								reading.ignore();
								record << m << endl;
								for (int i = 0; i < n; i++)
								{
									getline(reading, nazv);
									record << nazv << endl;
									for (int i = 0; i < m; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										reading >> ocen;
										record << ocen << endl;
										reading >> ocen;
										reading.ignore();
										record << ocen << endl;
									}
								}
							}
						}
						else
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							if (n == 0)
								record << n;
							else
								record << n << endl;
							for (int i = 0; i < n; i++)
							{
								if (i < n - 1)
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									record << n << endl;
									reading >> m;
									reading.ignore();
									record << m << endl;
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											reading >> ocen;
											record << ocen << endl;
											reading >> ocen;
											reading.ignore();
											record << ocen << endl;
										}
									}
								}
								else
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									if (n == 0)
									{
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m;
									}
									else
									{
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m << endl;
									}
									for (int i = 0; i < n; i++)
									{
										if (i < n - 1)
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												reading >> ocen;
												record << ocen << endl;
												reading >> ocen;
												reading.ignore();
												record << ocen << endl;
											}
										}
										else
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												if (i < m - 1)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
												else
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			cout << "Ошибка открытия второго буферного файла!";
			system("pause");
		}
	}
	else
	{
		cout << "Ошибка открытия буферного файла!";
		system("pause");
	}
	record.close();
	reading.close();
}
void dataDelete()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "Буфер пуст!" << endl;
		system("pause");
		return void();
	}
	if (AmountOfData() == 0)
	{
		cout << "Данных для удаления больше нет!" << endl;
		system("pause");
		return void();
	}
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string nazv;
		int ocen;
		int n;
		reading >> n;
		reading.ignore();
		for (int i = 0; i < n; i++)
		{
			int n;
			getline(reading, nazv);
			cout << i + 1 << "." << nazv << " ";
			reading >> n;
			reading.ignore();
			for (int i = 0; i < n; i++)
			{
				int n;
				getline(reading, nazv);
				reading >> n;
				reading.ignore();
				for (int i = 0; i < n; i++)
				{
					int n;
					int m;
					getline(reading, nazv);
					reading >> n;
					reading >> m;
					reading.ignore();
					for (int i = 0; i < n; i++)
					{
						getline(reading, nazv);
						for (int i = 0; i < m; i++)
						{
							getline(reading, nazv);
							reading >> ocen;
							reading >> ocen;
							reading.ignore();
						}
					}
				}
			}
		}
		int a;
		cout << "\n1.Выбрать институт для удаления 2.Далее\n";
		cin >> a;
		if (a == 1)
		{
			if (AmountOfData() == 1)
			{
				int a;
				cout << "В буфере только один институт. Хотите удалить его?\n1.Да 2.Нет\n";
				cin >> a;
				if (a == 1)
				{
					fstream file("Buffer.txt", ios::out);
					file.clear();
					file << 0;
					file.close();
					return void();
				}
				else if (a == 2)
				{
					return void();
				}
				else
				{
					while (a > 2 || a < 1)
					{
						cout << "Ошибка ввода!";
						cin >> a;
					}
					if (a == 2)
					{
						return void();
					}
					else
					{
						fstream file("Buffer.txt", ios::out);
						file.clear();
						file << 0;
						file.close();
						return void();
					}
				}
			}
			reading.close();
			Copy();
			ifstream reading("Buffer_.txt");
			ofstream record("Buffer.txt", ios::out);
			if (reading)
			{
				if (record)
				{
					string nazv;
					int ocen;
					int n;
					reading >> n;
					int b = n;
					reading.ignore();
					int _n;
					cout << "Выберите номер элемента, который хотите удалить: ";
					cin >> _n;
					_n--;
					system("cls");
					record << n-1 << endl;
					if (_n >= 0 && _n < n)
					{
						for (int j = 0; j < n; j++)
						{
							if (j != _n)
							{
								if (j < n - 1)
								{
									if ((j + 2 == b) && (_n + 1 == b))
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										if (n == 0)
											record << n;
										else
											record << n << endl;
										for (int i = 0; i < n; i++)
										{
											if (i < n - 1)
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												record << n << endl;
												for (int i = 0; i < n; i++)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
											}
											else
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												if (n == 0)
													record << n;
												else
													record << n << endl;
												for (int i = 0; i < n; i++)
												{
													if (i < n - 1)
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
														for (int i = 0; i < n; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
													}
													else
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if (n == 0)
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m;
														}
														else
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														for (int i = 0; i < n; i++)
														{
															if (i < n - 1)
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
															}
															else
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	if (i < m - 1)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen << endl;
																	}
																	else
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int i = 0; i < n; i++)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int i = 0; i < n; i++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
										}
									}
								}
								else
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int i = 0; i < n; i++)
									{
										if (i < n - 1)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int i = 0; i < n; i++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
										}
										else
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if (n == 0)
												record << n;
											else
												record << n << endl;
											for (int i = 0; i < n; i++)
											{
												if (i < n - 1)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if (n == 0)
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int i = 0; i < n; i++)
													{
														if (i < n - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
							else
							{								
								int n;
								getline(reading, nazv);
								reading >> n;
								reading.ignore();
								for (int i = 0; i < n; i++)
								{
									int n;
									getline(reading, nazv);
									reading >> n;
									reading.ignore();
									for (int i = 0; i < n; i++)
									{
										int n;
										int m;
										getline(reading, nazv);
										reading >> n;
										reading >> m;
										reading.ignore();
										for (int i = 0; i < n; i++)
										{
											getline(reading, nazv);
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												reading >> ocen;
												reading >> ocen;
												reading.ignore();
											}
										}
									}
								}
								
							}
						}
						cout << "Вы успешно изменили данные!" << endl;
						system("pause");
					}
					else
					{
						cout << "Элемента с таким номером не существует!" << endl;
						system("Pause");
						return void();
					}

					reading.close();
					record.close();
					remove("Buffer_.txt");
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
			}
			else
			{
				cout << "Ошибка открытия буферного файла!\n";
				system("Pause");
			}
		}
		else if (a == 2)
		{
			int b=-1;
			reading.close();
			ifstream reading("Buffer.txt");
			if (reading)
			{
				cout << "Выберите номер института: ";
				cin >> b;
				system("cls");
				string nazv;
				int ocen;
				int n;
				reading >> n;
				reading.ignore();
				for (int j = 0; j < n; j++)
				{
					int n;
					getline(reading, nazv);
					reading >> n;
					reading.ignore();
					if ((n == 0) && (j + 1 == b))
					{
						cout<<"Данных для удаления больше нет!" << endl;
						system("pause");
						reading.close();
						return void();
					}
					for (int i = 0; i < n; i++)
					{
						int n;
						getline(reading, nazv);
						if (j + 1 == b)
							cout << i + 1 << "." << nazv << " ";
						reading >> n;
						reading.ignore();
						for (int i = 0; i < n; i++)
						{
							int n;
							int m;
							getline(reading, nazv);
							reading >> n;
							reading >> m;
							reading.ignore();
							for (int i = 0; i < n; i++)
							{
								getline(reading, nazv);
								for (int i = 0; i < m; i++)
								{
									getline(reading, nazv);
									reading >> ocen;
									reading >> ocen;
									reading.ignore();
								}
							}
						}
					}
				}
				reading.close();
			}
			else
			{
				b = -1;
				cout << "Ошибка открытия буферного файла!\n";
				system("Pause");
			}
			cout << "\n1.Выбрать кафедру для удаления 2.Далее\n";
			cin >> a;
			if (a == 1)
			{
				reading.close();
				Copy();
				ifstream reading("Buffer_.txt");
				ofstream record("Buffer.txt", ios::out);
				if (reading)
				{
					if (record)
					{
						string nazv;
						int ocen;
						int n;
						reading >> n;
						int bo = n;
						reading.ignore();
						int l;
						cout << "Выберите номер элемента, который хотите удалить: ";
						cin >> l;
						system("cls");
						record << n << endl;
						for (int j = 0; j < n; j++)
						{
							if (j < n - 1)
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								int yo = n;
								reading.ignore();
								if (j+1==b)
								{
									record << n-1<<endl;
								}
								else
									record << n <<endl;
								for (int i = 0; i < n; i++)
								{
									if ((j+1!=b) || (i+1!=l))
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										reading >> n;
										reading.ignore();
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											reading >> n;
											reading >> m;
											reading.ignore();
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													reading >> ocen;
													reading >> ocen;
													reading.ignore();
												}
											}
										}	
									}
								}
							}
							else
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								int no = n;
								if (j + 1 == b)
								{
									if (n == 1)
										record << 0;
									else 
										record << n - 1 << endl;
								}
								else
								{
									if (n == 0)
										record << n;
									else
										record << n << endl;
								}
								reading.ignore();
								for (int r = 0; r < n; r++)
								{
									if ((j + 1 != b) || (r + 1 != l))
									{
										if (r < n - 1)
										{
											if ((r+2==no )&&(no==l)&&(j+1==b))
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												if (n == 0)
													record << n;
												else
													record << n << endl;
												for (int i = 0; i < n; i++)
												{
													if (i < n - 1)
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
														for (int i = 0; i < n; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
													}
													else
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if (n == 0)
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m;
														}
														else
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														for (int i = 0; i < n; i++)
														{
															if (i < n - 1)
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
															}
															else
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	if (i < m - 1)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen << endl;
																	}
																	else
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen;
																	}
																}
															}
														}
													}
												}
											}
											else
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												record << n << endl;
												for (int i = 0; i < n; i++)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
											}
										}
										else
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if (n == 0)
												record << n;
											else
												record << n << endl;
											for (int i = 0; i < n; i++)
											{
												if (i < n - 1)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if (n == 0)
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int i = 0; i < n; i++)
													{
														if (i < n - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen;
																}
															}
														}
													}
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										reading >> n;
										reading.ignore();
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											reading >> n;
											reading >> m;
											reading.ignore();
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													reading >> ocen;
													reading >> ocen;
													reading.ignore();
												}
											}
										}
									}
								}
							}	
						}
						cout << "Вы успешно удалили данные!" << endl;
						system("pause");					
						reading.close();
						record.close();
						remove("Buffer_.txt");
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
			}
			else if (a == 2)
			{
				int c=-1;
				reading.close();
				ifstream reading("Buffer.txt");
				if (reading)
				{
					cout << "Выберите номер кафедры: ";
					cin >> c;
					system("cls");
					string nazv;
					int ocen;
					int n;
					reading >> n;
					reading.ignore();
					for (int j = 0; j < n; j++)
					{
						int n;
						getline(reading, nazv);
						reading >> n;
						reading.ignore();
						for (int r = 0; r < n; r++)
						{
							int n;
							getline(reading, nazv);
							reading >> n;
							if ((n == 0) && (j + 1 == b) && (r + 1 == c))
							{
								cout << "Данных для удаления больше нет!" << endl;
								system("pause");
								reading.close();
								return void();
							}
							reading.ignore();
							for (int i = 0; i < n; i++)
							{
								int n;
								int m;
								getline(reading, nazv);
								if ((j + 1 == b) && (r + 1 == c))
									cout << i + 1 << "." << nazv << " ";
								reading >> n;
								reading >> m;
								reading.ignore();
								for (int i = 0; i < n; i++)
								{
									getline(reading, nazv);
									for (int i = 0; i < m; i++)
									{
										getline(reading, nazv);
										reading >> ocen;
										reading >> ocen;
										reading.ignore();
									}
								}
							}
						}
					}
					reading.close();
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
				cout << "\n1.Выбрать группу для удаления 2.Далее\n";
				cin >> a;
				if (a == 1)
				{
					reading.close();
					Copy();
					ifstream reading("Buffer_.txt");
					ofstream record("Buffer.txt", ios::out);
					if (reading)
					{
						if (record)
						{
							string nazv;
							int ocen;
							int n;
							reading >> n;
							int bo = n;
							reading.ignore();
							int t;
							cout << "Выберите номер элемента, который хотите удалить: ";
							cin >> t;
							system("cls");
							record << n << endl;
							for (int j = 0; j < n; j++)
							{
								if (j < n - 1)
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									int yo = n;
									reading.ignore();
									record << n << endl;
									for (int r = 0; r < n; r++)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										int eo = n;
										reading.ignore();
										if ((j + 1 == b) && (r + 1 == c))
										{
											record << n - 1 << endl;
										}
										else
											record << n << endl;
										for (int e = 0; e < n; e++)
										{
											if ((j + 1 != b) || (r + 1 != c) || (e + 1 != t))
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
											else
											{
												int n;
												int m;
												getline(reading, nazv);
												reading >> n;
												reading >> m;
												reading.ignore();
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													for (int i = 0; i < m; i++)
													{
														int ocen;
														getline(reading, nazv);
														reading >> ocen;
														reading >> ocen;
														reading.ignore();
													}
												}
											}
										}
									
									}
								}
								else
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int r = 0; r < n; r++)
									{
										if (r < n - 1)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if ((j + 1 == b) && (r + 1 == c))
											{
												record << n - 1 << endl;
											}
											else
												record << n << endl;
											for (int e = 0; e < n; e++)
											{
												if ((j + 1 != b) || (r + 1 != c) || (e + 1 != t))
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													reading >> n;
													reading >> m;
													reading.ignore();
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														for (int i = 0; i < m; i++)
														{
															int ocen;
															getline(reading, nazv);
															reading >> ocen;
															reading >> ocen;
															reading.ignore();
														}
													}
												}
											}
										}
										else
										{
											int wo;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> wo;
											reading.ignore();
											if ((j + 1 == b) && (r + 1 == c))
											{
												if (wo==1)
													record << 0;
												else
													record << wo - 1 << endl;
											}
											else
											{
												if (wo == 0)
													record << wo;
												else
													record << wo << endl;
											}
											for (int e = 0; e < wo; e++)
											{
												if ((j + 1 != b) || (r + 1 != c) || (e + 1 != t))
												{
													if (e < wo - 1)
													{
														if ((wo == t) && (e + 2 == wo)&&(j+1==b)&&(r+1==c))
														{
															int n;
															int m;
															getline(reading, nazv);
															record << nazv << endl;
															reading >> n;
															if (n == 0)
															{
																record << n << endl;
																reading >> m;
																reading.ignore();
																record << m;
															}
															else
															{
																record << n << endl;
																reading >> m;
																reading.ignore();
																record << m << endl;
															}
															for (int i = 0; i < n; i++)
															{
																if (i < n - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	for (int i = 0; i < m; i++)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen << endl;
																	}
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	for (int i = 0; i < m; i++)
																	{
																		if (i < m - 1)
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen << endl;
																		}
																		else
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen;
																		}
																	}
																}
															}
														}
														else
														{
															int n;
															int m;
															getline(reading, nazv);
															record << nazv << endl;
															reading >> n;
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
															for (int i = 0; i < n; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
															}
														}
													}
													else
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if (n == 0)
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m;
														}
														else
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														for (int i = 0; i < n; i++)
														{
															if (i < n - 1)
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
															}
															else
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	if (i < m - 1)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen << endl;
																	}
																	else
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen;
																	}
																}
															}
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													reading >> n;
													reading >> m;
													reading.ignore();
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														for (int i = 0; i < m; i++)
														{
															int ocen;
															getline(reading, nazv);
															reading >> ocen;
															reading >> ocen;
															reading.ignore();
														}
													}
												}		
											}
										}
									}
								}
							}
							cout << "Вы успешно удалили данные!" << endl;
							system("pause");
							reading.close();
							record.close();
							remove("Buffer_.txt");
						}
						else
						{
							cout << "Ошибка открытия буферного файла!\n";
							system("Pause");
						}
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
				}
				else if (a == 2)
				{
					int d=-1;
					reading.close();
					ifstream reading("Buffer.txt");
					if (reading)
					{
						cout << "Выберите номер группы: ";
						cin >> d;
						system("cls");
						string nazv;
						int ocen;
						int n;
						reading >> n;
						reading.ignore();
						for (int j = 0; j < n; j++)
						{
							int n;
							getline(reading, nazv);
							reading >> n;
							reading.ignore();
							for (int r = 0; r < n; r++)
							{
								int n;
								getline(reading, nazv);
								reading >> n;
								reading.ignore();
								for (int p = 0; p < n; p++)
								{
									int n;
									int m;
									getline(reading, nazv);
									reading >> n;
									if ((n == 0) && (j + 1 == b) && (r + 1 == c) && (p + 1 == d))
									{
										cout << "Данных для удаления больше нет!" << endl;
										system("pause");
										reading.close();
										return void();
									}
									reading >> m;
									reading.ignore();
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
											cout << i + 1 << "." << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											reading >> ocen;
											reading >> ocen;
											reading.ignore();
										}
									}
								}
							}
						}
						reading.close();
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
					cout << "1.Выбрать студента для удаления 2.Выйти\n";
					cin >> a;
					if (a == 1)
					{
						reading.close();
						Copy();
						ifstream reading("Buffer_.txt");
						ofstream record("Buffer.txt", ios::out);
						if (reading)
						{
							if (record)
							{
								string nazv;
								int ocen;
								int n;
								reading >> n;
								int bo = n;
								reading.ignore();
								int y;
								cout << "Выберите номер элемента, который хотите удалить: ";
								cin >> y;
								system("cls");
								record << n << endl;
								for (int j = 0; j < n; j++)
								{
									if (j < n - 1)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int r = 0; r < n; r++)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int e = 0; e < n; e++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												if ((j + 1 == b) && (r + 1 == c)&&(e+1==d))
													record << n - 1 << endl;
												else
													record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int k = 0; k < n; k++)
												{
													if ((j + 1 != b) || (r + 1 != c) || (e + 1 != d) || (k + 1 != y))
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
													else
													{
														getline(reading, nazv);
														for (int i = 0; i < m; i++)
														{
															int ocen;
															getline(reading, nazv);
															reading >> ocen;
															reading >> ocen;
															reading.ignore();
														}

													}
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										if (n == 0)
											record << n;
										else
											record << n << endl;
										for (int r = 0; r < n; r++)
										{
											if (r < n - 1)
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												record << n << endl;
												for (int e = 0; e < n; e++)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if ((j + 1 == b) && (r + 1 == c) && (e + 1 == d))
														record << n - 1 << endl;
													else
														record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int k = 0; k < n; k++)
													{
														if ((j + 1 != b) || (r + 1 != c) || (e + 1 != d) || (k + 1 != y))
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															for (int i = 0; i < m; i++)
															{
																int ocen;
																getline(reading, nazv);
																reading >> ocen;
																reading >> ocen;
																reading.ignore();
															}
														}
													}
												}
											}
											else
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												if (n == 0)
													record << n;
												else
													record << n << endl;
												for (int e = 0; e < n; e++)
												{
													if (e < n - 1)
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if ((j + 1 == b) && (r + 1 == c) && (e + 1 == d))
															record << n - 1 << endl;
														else
															record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
														for (int k = 0; k < n; k++)
														{
															if ((j + 1 != b) || (r + 1 != c) || (e + 1 != d) || (k + 1 != y))
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
															}
															else
															{
																getline(reading, nazv);
																for (int i = 0; i < m; i++)
																{
																	int ocen;
																	getline(reading, nazv);
																	reading >> ocen;
																	reading >> ocen;
																	reading.ignore();
																}
															}
														}
													}
													else
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if ((j + 1 ==b) && (r + 1 == c)&&(e+1==d))
														{
															if (n == 1)
															{
																record <<0<<endl;
																reading >> m;
																reading.ignore();
																record << m;
															}
															else
															{
																record << n - 1 << endl;
																reading >> m;
																reading.ignore();
																record << m << endl;
															}
														}
														else
														{
															if (n == 0)
															{
																record << n << endl;
																reading >> m;
																reading.ignore();
																record << m;
															}
															else
															{
																record << n << endl;
																reading >> m;
																reading.ignore();
																record << m << endl;
															}
														}														
														for (int k = 0; k < n; k++)
														{
															if ((j + 1 != b) || (r + 1 != c) || (e + 1 != d) || (k + 1 != y))
															{
																if (k < n - 1)
																{
																	if ((n==y) && (k + 2 == n) && (j + 1 == b) && (r + 1 == c) && (e + 1 == d))
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		for (int i = 0; i < m; i++)
																		{
																			if (i < m - 1)
																			{
																				getline(reading, nazv);
																				record << nazv << endl;
																				reading >> ocen;
																				record << ocen << endl;
																				reading >> ocen;
																				reading.ignore();
																				record << ocen << endl;
																			}
																			else
																			{
																				getline(reading, nazv);
																				record << nazv << endl;
																				reading >> ocen;
																				record << ocen << endl;
																				reading >> ocen;
																				reading.ignore();
																				record << ocen;
																			}
																		}
																	}
																	else
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		for (int i = 0; i < m; i++)
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen << endl;
																		}
																	}
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	for (int i = 0; i < m; i++)
																	{
																		if (i < m - 1)
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen << endl;
																		}
																		else
																		{
																			getline(reading, nazv);
																			record << nazv << endl;
																			reading >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading.ignore();
																			record << ocen;
																		}
																	}
																}
															}
															else
															{
																getline(reading, nazv);
																for (int i = 0; i < m; i++)
																{
																	int ocen;
																	getline(reading, nazv);
																	reading >> ocen;
																	reading >> ocen;
																	reading.ignore();
																}
															}
														}
													}
												}
											}
										}
									}
								}
								cout << "Вы успешно удалили данные!" << endl;
								system("pause");
								reading.close();
								record.close();
								remove("Buffer_.txt");
							}
							else
							{
								cout << "Ошибка открытия буферного файла!\n";
								system("Pause");
							}
						}
						else
						{
							cout << "Ошибка открытия буферного файла!\n";
							system("Pause");
						}
					}
					else if (a == 2)
					{
						return void();
					}
				}
				else
				{
					cout << "Ошибка ввода!" << endl;
					system("pause");
					return void();
				}
			}
			else
			{
				cout << "Ошибка ввода!" << endl;
				system("pause");
				return void();
			}
		}
		else
		{
			cout << "Ошибка ввода!" << endl;
			system("pause");
			return void();
		}
	}
	else
	{
		cout << "Ошибка открытия буферного файла!\n";
		system("Pause");
	}
}
void dataAdd()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "Буфер пуст!" << endl;
		system("pause");
		return void();
	}
	if (AmountOfData() == 0)
	{
		int a;
		cout << "В базе данных нет ни одного института\n1.Добавить 2.Выйти" << endl;
		cin >> a;
		if (a == 1)
		{
			string nazv;
			ofstream record("Buffer.txt", ios::out);
			record << 1 << endl;
			cout << "Введите название института: ";
			while (cin.get() != '\n');
			getline(cin, nazv);
			record << nazv<<endl;
			record << 0;
			record.close();
			cout << "Вы успешно добавили инстиутут!";
			return void();
		}
		else if (a==2)
			return void();
		else
		{
			cout << "Ошибка ввода!";
			system("pause");
			return void();
		}
	}
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string nazv;
		int ocen;
		int n;
		reading >> n;
		reading.ignore();
		for (int i = 0; i < n; i++)
		{
			int n;
			getline(reading, nazv);
			cout << i + 1 << "." << nazv << " ";
			reading >> n;
			reading.ignore();
			for (int i = 0; i < n; i++)
			{
				int n;
				getline(reading, nazv);
				reading >> n;
				reading.ignore();
				for (int i = 0; i < n; i++)
				{
					int n;
					int m;
					getline(reading, nazv);
					reading >> n;
					reading >> m;
					reading.ignore();
					for (int i = 0; i < n; i++)
					{
						getline(reading, nazv);
						for (int i = 0; i < m; i++)
						{
							getline(reading, nazv);
							reading >> ocen;
							reading >> ocen;
							reading.ignore();
						}
					}
				}
			}
		}
		int a;
		cout << "\n1.Добавить институт 2.Далее\n";
		cin >> a;
		if (a == 1)
		{
			reading.close();
			Copy();
			ifstream reading("Buffer_.txt");
			ofstream record("Buffer.txt", ios::out);
			if (reading)
			{
				if (record)
				{
					string inst;
					string nazv;
					int ocen;
					int n;
					reading >> n;
					reading.ignore();
					system("cls");
					record << n+1 << endl;
					cout << "Введите название института: ";
					while (cin.get() != '\n');
					getline(cin, inst);
					for (int i = 0; i < n; i++)
					{
						if (i < n - 1)
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							record << n << endl;
							for (int i = 0; i < n; i++)
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								reading.ignore();
								record << n << endl;
								for (int i = 0; i < n; i++)
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									record << n << endl;
									reading >> m;
									reading.ignore();
									record << m << endl;
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											reading >> ocen;
											record << ocen << endl;
											reading >> ocen;
											reading.ignore();
											record << ocen << endl;
										}
									}
								}
							}
						}
						else
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							if (n == 0)
								record << n;
							else
								record << n << endl;
							for (int i = 0; i < n; i++)
							{
								if (i < n - 1)
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int i = 0; i < n; i++)
									{
										int n;
										int m;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m << endl;
										for (int i = 0; i < n; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												reading >> ocen;
												record << ocen << endl;
												reading >> ocen;
												reading.ignore();
												record << ocen << endl;
											}
										}
									}
								}
								else
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int i = 0; i < n; i++)
									{
										if (i < n - 1)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
										else
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											if (n == 0)
											{
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m;
											}
											else
											{
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
											}
											for (int i = 0; i < n; i++)
											{
												if (i < n - 1)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
												else
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														if (i < m - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen;
														}
													}
												}
											}
										}
									}
								}
							}
							record << endl << inst << endl;
							record << 0;
						}
					}
					cout <<"Вы успешно добавили институт!\n";
					system("pause");
					reading.close();
					record.close();
					remove("Buffer_.txt");
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
			}
			else
			{
				cout << "Ошибка открытия буферного файла!\n";
				system("Pause");
			}
		}
		else if (a == 2)
		{
			int pi=2;
			int b=-1;
			reading.close();
			ifstream reading("Buffer.txt");
			if (reading)
			{
				cout << "Выберите номер института: ";
				cin >> b;
				system("cls");
				string nazv;
				int ocen;
				int n;
				reading >> n;
				int no = n;
				reading.ignore();
				for (int j = 0; j < n; j++)
				{
					int n;
					getline(reading, nazv);
					reading >> n;
					if ((n == 0) && (j + 1 == b))
						pi = 0;
					else if (j + 1 == b)
						pi = 1;
					reading.ignore();
					for (int i = 0; i < n; i++)
					{
						int n;
						getline(reading, nazv);
						if (j + 1 == b)
							cout << i + 1 << "." << nazv << " ";
						reading >> n;
						reading.ignore();
						for (int i = 0; i < n; i++)
						{
							int n;
							int m;
							getline(reading, nazv);
							reading >> n;
							reading >> m;
							reading.ignore();
							for (int i = 0; i < n; i++)
							{
								getline(reading, nazv);
								for (int i = 0; i < m; i++)
								{
									getline(reading, nazv);
									reading >> ocen;
									reading >> ocen;
									reading.ignore();
								}
							}
						}
					}
				}
			}
			else
			{
				cout << "Ошибка открытия буферного файла!\n";
				system("Pause");
			}
			if (pi == 0)
			{
				int vopr;
				system("cls");
				cout << "В институте нет кафедр\n1.Добавить 2.Выйти\n";
				cin >> vopr;
				if (vopr == 2)
				{
					reading.close();
					return void();
				}
				else if (vopr != 1)
				{
					cout << "Ошибка ввода!\n";
					system("pause");
					reading.close();
					return void();
				}
				else
					a = 1;
			}
			else if (pi == 1)
			{
				cout << "\n1.Добавить кафедру 2.Далее\n";
				cin >> a;
			}
			else
			{
				cout << "Ошибка!!!";
				system("pause");
				return void();
			}
			if (a == 1)
			{
				reading.close();
				Copy();
				ifstream reading("Buffer_.txt");
				ofstream record("Buffer.txt", ios::out);
				if (reading)
				{
					if (record)
					{
						string nazv;
						int ocen;
						int n;
						reading >> n;
						reading.ignore();
						system("cls");
						record << n << endl;
						for (int j = 0; j < n; j++)
						{
							if (j < n - 1)
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								reading.ignore();
								if (j + 1 == b)
								{
									record << n+1 << endl;
								}
								else
									record << n << endl;
								for (int r = 0; r < n; r++)
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int i = 0; i < n; i++)
									{
										int n;
										int m;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m << endl;
										for (int i = 0; i < n; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												reading >> ocen;
												record << ocen << endl;
												reading >> ocen;
												reading.ignore();
												record << ocen << endl;
											}
										}
									}	
								}
								if (j + 1 == b)
								{
									string kaf;
									cout << "Введите название кафедры: ";
									while (cin.get() != '\n');
									getline(cin, kaf);
									record << kaf << endl;
									record << 0 << endl;
								}
							}
							else
							{
								int n;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								reading.ignore();
								if ((n == 0) && (j + 1 == b))
								{
									record << n + 1 << endl;
									string kaf;
									cout << "Введите название кафедры: ";
									while (cin.get() != '\n');
									getline(cin, kaf);
									record << kaf << endl;
									record << 0;
								}
								else if (j + 1 == b)
								{
									record << n + 1 << endl;
								}
								else
								{
									if (n == 0)
										record << n;
									else
										record << n << endl;
								}
								for (int r = 0; r < n; r++)
								{
									if (r < n - 1)
									{
										int n;									
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int i = 0; i < n; i++)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										if (n == 0)
											record << n;
										else
											record << n << endl;
										for (int i = 0; i < n; i++)
										{
											if (i < n - 1)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
											else
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												if (n == 0)
												{
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m;
												}
												else
												{
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
												}
												for (int i = 0; i < n; i++)
												{
													if (i < n - 1)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
													else
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															if (i < m - 1)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
															else
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen;
															}
														}
													}
												}
											}
										}
										if (j + 1 == b)
										{
											string kaf;
											cout << "Введите название кафедры: ";
											while (cin.get() != '\n');
											getline(cin, kaf);
											record << endl<<kaf << endl;
											record << 0;
										}
									}
								}
							}
						}
						cout << "Вы успешно добавили кафедру!" << endl;
						system("pause");
						reading.close();
						record.close();
						remove("Buffer_.txt");
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
			}
			else if (a == 2)
			{
				int c=-1;
				reading.close();
				ifstream reading("Buffer.txt");
				if (reading)
				{
					cout << "Выберите номер кафедры: ";
					cin >> c;
					system("cls");
					string nazv;
					int ocen;
					int n;
					reading >> n;
					reading.ignore();
					for (int j = 0; j < n; j++)
					{
						int n;
						getline(reading, nazv);
						reading >> n;
						reading.ignore();
						for (int r = 0; r < n; r++)
						{
							int n;
							getline(reading, nazv);
							reading >> n;
							if ((n == 0) && (j + 1 == b) && (r + 1 == c))
								pi = 0;
							else if ((j + 1 == b) && (r + 1 == c))
								pi = 1;
							reading.ignore();
							for (int i = 0; i < n; i++)
							{
								int n;
								int m;
								getline(reading, nazv);
								if ((j + 1 == b) && (r + 1 == c))
									cout << i + 1 << "." << nazv << " ";
								reading >> n;
								reading >> m;
								reading.ignore();
								for (int i = 0; i < n; i++)
								{
									getline(reading, nazv);
									for (int i = 0; i < m; i++)
									{
										getline(reading, nazv);
										reading >> ocen;
										reading >> ocen;
										reading.ignore();
									}
								}
							}
						}
					}
				}
				else
				{
					cout << "Ошибка открытия буферного файла!\n";
					system("Pause");
				}
				if (pi == 0)
				{
					int vopr;
					system("cls");
					cout << "В кафедре нет групп\n1.Добавить 2.Выйти\n";
					cin >> vopr;
					if (vopr == 2)
					{
						reading.close();
						return void();
					}
					else if (vopr != 1)
					{
						cout << "Ошибка ввода!\n";
						system("pause");
						reading.close();
						return void();
					}
					else
						a = 1;
				}
				else if (pi == 1)
				{
					cout << "\n1.Добавить группу 2.Далее\n";
					cin >> a;
				}
				else
				{
				cout << "Ошибка!!!";
				system("pause");
				return void();
				}
				if (a == 1)
				{
					reading.close();
					Copy();
					ifstream reading("Buffer_.txt");
					ofstream record("Buffer.txt", ios::out);
					if (reading)
					{
						if (record)
						{
							string nazv;
							int ocen;
							int n;
							reading >> n;
							reading.ignore();
							system("cls");
							record << n << endl;
							for (int j = 0; j < n; j++)
							{
								if (j < n - 1)
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									record << n << endl;
									for (int r = 0; r < n; r++)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										if ((j + 1 == b)&&(r+1==c))
										{
											record << n + 1 << endl;
										}
										else
											record << n << endl;
										for (int p = 0; p < n; p++)
										{
											int n;
											int m;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											record << n << endl;
											reading >> m;
											reading.ignore();
											record << m << endl;
											for (int i = 0; i < n; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												for (int i = 0; i < m; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
											}		
										}
										if ((j + 1 == b) && (r + 1 == c))
										{
											int kol;
											string gr;
											cout << "Введите название группы: ";
											while (cin.get() != '\n');
											getline(cin, gr);
											cout << "Введите колличество предметов у группы: ";
											cin >> kol;
											record << gr << endl;
											record << 0 << endl;
											record << kol << endl;
										}
									}
								}
								else
								{
									int n;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									reading.ignore();
									if (n == 0)
										record << n;
									else
										record << n << endl;
									for (int r = 0; r < n; r++)
									{
										if (r < n - 1)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if ((j + 1 == b) && (r + 1 == c))
											{
												record << n + 1 << endl;
											}
											else
												record << n << endl;
											for (int p = 0; p < n; p++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												record << n << endl;
												reading >> m;
												reading.ignore();
												record << m << endl;
												for (int i = 0; i < n; i++)
												{
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
													}
												}
											}
											if ((j + 1 == b) && (r + 1 == c))
											{
												int kol;
												string gr;
												cout << "Введите название группы: ";
												while (cin.get() != '\n');
												getline(cin, gr);
												cout << "Введите колличество предметов у группы: ";
												cin >> kol;
												record << gr << endl;
												record << 0 << endl;
												record << kol << endl;
											}
										}
										else
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											if ((n == 0) && (j + 1 == b) && (r + 1 == c))
											{
												record << n + 1 << endl;
												int kol;
												string gr;
												cout << "Введите название группы: ";
												while (cin.get() != '\n');
												getline(cin, gr);
												cout << "Введите колличество предметов у группы: ";
												cin >> kol;
												record << gr << endl;
												record << 0 << endl;
												record << kol;
											}
											else if ((j + 1 == b) && (r + 1 == c))
											{
												record << n + 1 << endl;
											}
											else
											{
												if (n == 0)
													record << n;
												else
													record << n << endl;
											}								
											for (int p = 0; p < n; p++)
											{
												if (p < n - 1)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													for (int i = 0; i < n; i++)
													{
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
														}
													}
												}
												else
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if (n == 0)
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int i = 0; i < n; i++)
													{
														if (i < n - 1)
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
															}
														}
														else
														{
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}
																else
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen;
																}
															}
														}
													}	
													if ((j + 1 == b) && (r + 1 == c))
													{
														int kol;
														string gr;
														cout << "Введите название группы: ";
														while (cin.get() != '\n');
														getline(cin, gr);
														cout << "Введите колличество предметов у группы: ";
														cin >> kol;
														record << endl << gr << endl;
														record << 0 << endl;
														record << kol;
													}
												}
											}
										}
									}
								}
							}
							cout << "Вы успешно добавили группу!" << endl;
							system("pause");
							reading.close();
							record.close();
							remove("Buffer_.txt");
						}
						else
						{
							cout << "Ошибка открытия буферного файла!\n";
							system("Pause");
						}
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
				}
				else if (a == 2)
				{
					int d=-1;
					reading.close();
					ifstream reading("Buffer.txt");
					if (reading)
					{
						cout << "Выберите номер группы: ";
						cin >> d;
						system("cls");
						string nazv;
						int ocen;
						int n;
						reading >> n;
						reading.ignore();
						for (int j = 0; j < n; j++)
						{
							int n;
							getline(reading, nazv);
							reading >> n;
							reading.ignore();
							for (int r = 0; r < n; r++)
							{
								int n;
								getline(reading, nazv);
								reading >> n;
								reading.ignore();
								for (int p = 0; p < n; p++)
								{
									int n;
									int m;
									getline(reading, nazv);
									reading >> n;
									if ((n == 0) && (j + 1 == b) && (r + 1 == c) && (p + 1 == d))
										pi = 0;
									else if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
										pi = 1;
									reading >> m;
									reading.ignore();
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
											cout << i + 1 << "." << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											reading >> ocen;
											reading >> ocen;
											reading.ignore();
										}
									}
								}
							}
						}
					}
					else
					{
						cout << "Ошибка открытия буферного файла!\n";
						system("Pause");
					}
					if (pi == 0)
					{
						int vopr;
						system("cls");
						cout << "В группе нет студентов\n1.Добавить 2.Выйти\n";
						cin >> vopr;
						if (vopr == 2)
						{
							reading.close();
							return void();
						}
						else if (vopr != 1)
						{
							cout << "Ошибка ввода!\n";
							system("pause");
							reading.close();
							return void();
						}
						else
						{
							cout << "Заполните список предметов, пожалуйста\n\n";
							system("pause");
							a = 1;
						}
					}
					else if (pi==1)
					{
						cout << "\n1.Добавить студента 2.выйти\n";
						cin >> a;
					}
					else
					{
						cout << "Ошибка!!!";
						system("pause");
						return void();
					}
					if (a == 1)
					{
						reading.close();
						Copy();
						ifstream reading("Buffer_.txt");
						ofstream record("Buffer.txt", ios::out);
						if (reading)
						{
							if (record)
							{
								string nazv;
								int ocen;
								int n;
								reading >> n;
								reading.ignore();
								system("cls");
								record << n << endl;
								for (int j = 0; j < n; j++)
								{
									if (j < n - 1)
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										record << n << endl;
										for (int r = 0; r < n; r++)
										{
											int n;
											getline(reading, nazv);
											record << nazv << endl;
											reading >> n;
											reading.ignore();
											record << n << endl;
											for (int p = 0; p < n; p++)
											{
												int n;
												int m;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												if ((n == 0) && (j + 1 == b) && (r + 1 == c)&&(p + 1 == d))
												{
													record << n + 1 << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
													int* kurs = new int[m];
													string* predm = new string[m];
													for (int i = 0; i < m; i++)
													{
														int a;
														string pred;
														cout << "Введите название предмета: ";
														while (cin.get() != '\n');
														getline(cin, pred);
														predm[i] = pred;
														cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
														cin >> a;
														a--;
														kurs[i] = a;
													}
													string fio;
													cout << "Введите ФИО студента: ";
													while (cin.get() != '\n');
													getline(cin, fio);
													record << fio << endl;
													for (int i = 0; i < m; i++)
													{
														int ocen;
														cout << "Оценка по предмету " << predm[i] << ": ";
														record << predm[i] << endl;
														cin >> ocen;
														record << ocen << endl;
														if (kurs[i] == 0)
														{
															int ocen;
															cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
															cin >> ocen;
															record << ocen << endl;
														}
														else
														{
															record << 0 << endl;
														}
													}
													delete[] predm;
													delete[] kurs;
												}
												else if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
												{
													record << n + 1 << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
												}
												else
												{
													record << n << endl;
													reading >> m;
													reading.ignore();
													record << m << endl;
												}
												for (int o = 0; o < n; o++)
												{
													int* kurs = new int[m];
													string* predm = new string[m];
													getline(reading, nazv);
													record << nazv << endl;
													for (int i = 0; i < m; i++)
													{
														getline(reading, nazv);
														predm[i] = nazv;
														record << nazv << endl;
														reading >> ocen;
														record << ocen << endl;
														reading >> ocen;
														reading.ignore();
														record << ocen << endl;
														kurs[i] = ocen;
													}
													if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == n))
													{
														string fio;
														cout << "Введите ФИО студента: ";
														while (cin.get() != '\n');
														getline(cin, fio);
														record << fio << endl;
														for (int i = 0; i < m; i++)
														{
															int ocen;
															cout << "Оценка по предмету " << predm[i] << ": ";
															record << predm[i] << endl;
															cin >> ocen;
															record << ocen << endl;
															if (kurs[i] !=0)
															{
																int ocen;
																cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																cin >> ocen;
																record << ocen << endl;
															}
															else
															{
																record << 0 << endl;
															}
														}
													}
													if (o + 1 == n)
													{
														delete[] predm;
														delete[] kurs;
													}
												}
											}
										}
									}
									else
									{
										int n;
										getline(reading, nazv);
										record << nazv << endl;
										reading >> n;
										reading.ignore();
										if (n == 0)
											record << n;
										else
											record << n << endl;
										for (int r = 0; r < n; r++)
										{
											if (r < n - 1)
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												record << n << endl;
												for (int p = 0; p < n; p++)
												{
													int n;
													int m;
													getline(reading, nazv);
													record << nazv << endl;
													reading >> n;
													if ((n == 0) && (j + 1 == b) && (r + 1 == c) && (p + 1 == d))
													{
														record << n + 1 << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
														int* kurs = new int[m];
														string* predm = new string[m];
														for (int i = 0; i < m; i++)
														{
															int a;
															string pred;
															cout << "Введите название предмета: ";
															while (cin.get() != '\n');
															getline(cin, pred);
															predm[i] = pred;
															cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
															cin >> a;
															a--;
															kurs[i] = a;
														}
														string fio;
														cout << "Введите ФИО студента: ";
														while (cin.get() != '\n');
														getline(cin, fio);
														record << fio << endl;
														for (int i = 0; i < m; i++)
														{
															int ocen;
															cout << "Оценка по предмету " << predm[i] << ": ";
															record << predm[i] << endl;
															cin >> ocen;
															record << ocen << endl;
															if (kurs[i] == 0)
															{
																int ocen;
																cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																cin >> ocen;
																record << ocen << endl;
															}
															else
															{
																record << 0 << endl;
															}
														}
														delete[] predm;
														delete[] kurs;
													}
													else if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
													{
														record << n + 1 << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													else
													{
														record << n << endl;
														reading >> m;
														reading.ignore();
														record << m << endl;
													}
													for (int o = 0; o < n; o++)
													{
														int* kurs = new int[m];
														string* predm = new string[m];
														getline(reading, nazv);
														record << nazv << endl;
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															predm[i] = nazv;
															record << nazv << endl;
															reading >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading.ignore();
															record << ocen << endl;
															kurs[i] = ocen;
														}
														if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == n))
														{
															string fio;
															cout << "Введите ФИО студента: ";
															while (cin.get() != '\n');
															getline(cin, fio);
															record << fio << endl;
															for (int i = 0; i < m; i++)
															{
																int ocen;
																cout << "Оценка по предмету " << predm[i] << ": ";
																record << predm[i] << endl;
																cin >> ocen;
																record << ocen << endl;
																if (kurs[i] != 0)
																{
																	int ocen;
																	cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																	cin >> ocen;
																	record << ocen << endl;
																}
																else
																{
																	record << 0 << endl;
																}
															}
														}
														if (o + 1 == n)
														{
															delete[] predm;
															delete[] kurs;
														}
													}
												}
											}
											else
											{
												int n;
												getline(reading, nazv);
												record << nazv << endl;
												reading >> n;
												reading.ignore();
												if (n == 0)
													record << n;
												else
													record << n << endl;
												for (int p = 0; p < n; p++)
												{
													if (p < n - 1)
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if ((n == 0) && (j + 1 == b) && (r + 1 == c) && (p + 1 == d))
														{
															record << n + 1 << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
															int* kurs = new int[m];
															string* predm = new string[m];
															for (int i = 0; i < m; i++)
															{
																int a;
																string pred;
																cout << "Введите название предмета: ";
																while (cin.get() != '\n');
																getline(cin, pred);
																predm[i] = pred;
																cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
																cin >> a;
																a--;
																kurs[i] = a;
															}
															string fio;
															cout << "Введите ФИО студента: ";
															while (cin.get() != '\n');
															getline(cin, fio);
															record << fio << endl;
															for (int i = 0; i < m; i++)
															{
																int ocen;
																cout << "Оценка по предмету " << predm[i] << ": ";
																record << predm[i] << endl;
																cin >> ocen;
																record << ocen << endl;
																if (kurs[i] == 0)
																{
																	int ocen;
																	cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																	cin >> ocen;
																	record << ocen << endl;
																}
																else
																{
																	record << 0 << endl;
																}
															}
															delete[] predm;
															delete[] kurs;
														}
														else if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d))
														{
															record << n + 1 << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														else
														{
															record << n << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														for (int o = 0; o < n; o++)
														{
															int* kurs = new int[m];
															string* predm = new string[m];
															getline(reading, nazv);
															record << nazv << endl;
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																predm[i] = nazv;
																record << nazv << endl;
																reading >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading.ignore();
																record << ocen << endl;
																kurs[i] = ocen;
															}
															if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == n))
															{
																string fio;
																cout << "Введите ФИО студента: ";
																while (cin.get() != '\n');
																getline(cin, fio);
																record << fio << endl;
																for (int i = 0; i < m; i++)
																{
																	int ocen;
																	cout << "Оценка по предмету " << predm[i] << ": ";
																	record << predm[i] << endl;
																	cin >> ocen;
																	record << ocen << endl;
																	if (kurs[i] != 0)
																	{
																		int ocen;
																		cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																		cin >> ocen;
																		record << ocen << endl;
																	}
																	else
																	{
																		record << 0 << endl;
																	}
																}
															}
															if (o + 1 == n)
															{
																delete[] predm;
																delete[] kurs;
															}
														}
													}
													else
													{
														int n;
														int m;
														getline(reading, nazv);
														record << nazv << endl;
														reading >> n;
														if ((n == 0) && (j + 1 == b) && (r + 1 == c) && (p + 1 == d))
														{
															record << n + 1 << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
															int* kurs = new int[m];
															string* predm = new string[m];
															for (int i = 0; i < m; i++)
															{
																int a;
																string pred;
																cout << "Введите название предмета: ";
																while (cin.get() != '\n');
																getline(cin, pred);
																predm[i] = pred;
																cout << "Есть ли курсовая по этому предмету?\n1.Да 2.Нет ";
																cin >> a;
																a--;
																kurs[i] = a;
															}
															string fio;
															cout << "Введите ФИО студента: ";
															while (cin.get() != '\n');
															getline(cin, fio);
															record << fio << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	int ocen;
																	cout << "Оценка по предмету " << predm[i] << ": ";
																	record << predm[i] << endl;
																	cin >> ocen;
																	record << ocen << endl;
																	if (kurs[i] == 0)
																	{
																		int ocen;
																		cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																		cin >> ocen;
																		record << ocen << endl;
																	}
																	else
																	{
																		record << 0 << endl;
																	}
																}
																else
																{
																	int ocen;
																	cout << "Оценка по предмету " << predm[i] << ": ";
																	record << predm[i] << endl;
																	cin >> ocen;
																	record << ocen << endl;
																	if (kurs[i] == 0)
																	{
																		int ocen;
																		cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																		cin >> ocen;
																		record << ocen;
																	}
																	else
																	{
																		record << 0;
																	}
																}
															}
															delete[] predm;
															delete[] kurs;
														}
														else if ((j + 1 ==b) && (r + 1 == c) && (p + 1 == d))
														{
															record << n + 1 << endl;
															reading >> m;
															reading.ignore();
															record << m << endl;
														}
														else
														{
															if (n == 0)
															{
																record << n << endl;
																reading >> m;
																reading.ignore();
																record << m;
															}
															else
															{
																record << n << endl;
																reading >> m;
																reading.ignore();
																record << m << endl;
															}
														}
														for (int o = 0; o < n; o++)
														{
															if (o < n - 1)
															{
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	reading >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading.ignore();
																	record << ocen << endl;
																}	
															}
															else
															{
																int* kurs = new int[m];
																string* predm = new string[m];
																getline(reading, nazv);
																record << nazv << endl;
																for (int i = 0; i < m; i++)
																{
																	if (i < m - 1)
																	{
																		getline(reading, nazv);
																		predm[i] = nazv;
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen << endl;
																		kurs[i] = ocen;
																	}
																	else
																	{
																		getline(reading, nazv);
																		predm[i] = nazv;
																		record << nazv << endl;
																		reading >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading.ignore();
																		record << ocen;
																		kurs[i] = ocen;

																		if ((j + 1 == b) && (r + 1 == c) && (p + 1 == d) && (o + 1 == n))
																		{
																			string fio;
																			cout << "Введите ФИО студента: ";
																			while (cin.get() != '\n');
																			getline(cin, fio);
																			record << endl << fio << endl;
																			for (int i = 0; i < m; i++)
																			{
																				if (i < m - 1)
																				{
																					int ocen;
																					cout << "Оценка по предмету " << predm[i] << ": ";
																					record << predm[i] << endl;
																					cin >> ocen;
																					record << ocen << endl;
																					if (kurs[i] != 0)
																					{
																						int ocen;
																						cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																						cin >> ocen;
																						record << ocen << endl;
																					}
																					else
																					{
																						record << 0 << endl;
																					}
																				}
																				else
																				{
																					int ocen;
																					cout << "Оценка по предмету " << predm[i] << ": ";
																					record << predm[i] << endl;
																					cin >> ocen;
																					record << ocen << endl;
																					if (kurs[i] != 0)
																					{
																						int ocen;
																						cout << "Оценка за курсовую по предмету " << predm[i] << ": ";
																						cin >> ocen;
																						record << ocen;
																					}
																					else
																					{
																						record << 0;
																					}
																				}
																			}
																		}
																		if (o + 1 == n)
																		{
																			delete[] predm;
																			delete[] kurs;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
								cout << "Вы успешно добавили студента!" << endl;
								system("pause");
								reading.close();
								record.close();
								remove("Buffer_.txt");
							}
							else
							{
								cout << "Ошибка открытия буферного файла!\n";
								system("Pause");
							}
						}
						else
						{
							cout << "Ошибка открытия буферного файла!\n";
							system("Pause");
						}
					}
					else if (a == 2)
					{
						return void();
					}
				}
				else
				{
					cout << "Ошибка ввода!" << endl;
					system("pause");
					return void();
				}
			}
			else
			{
				cout << "Ошибка ввода!" << endl;
				system("pause");
				return void();
			}
		}
		else
		{
			cout << "Ошибка ввода!" << endl;
			system("pause");
			return void();
		}
	}
	else
	{
		cout << "Ошибка открытия буферного файла!\n";
		system("Pause");
	}
}
int AmountOfData()
{
	ifstream _buff("Buffer.txt");
	int n;
	if (_buff)
	{
		_buff >> n; 
	}
	else
	{
		cout << "Ошибка открытия файла!" << endl;
		return -1;
	}
	_buff.close();
	return n;
}
void dataSave()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "Буфер пуст!" << endl;
		system("pause");
		return void();
	}
	ifstream reading("Buffer.txt");
	string filename;
	cout << "Введите название файла(без разрешения .txt), в который вы хотите сохранить данные: ";
	while (cin.get() != '\n');
	getline(cin, filename);
	string full;
	string txt = ".txt";
	full = filename + txt;
	while (FileIsExist(full))
	{
		cout << "Файл с таким названием уже существует!\n";
		cout << "Пожалуйста, введи другое имя файла: ";
		getline(cin, filename);
		full = filename + txt;
	}
	ofstream record(full, ios::out);
	if (reading)
	{
		if (record)
		{
			string nazv;
			int ocen;
			int n;
			reading >> n;
			reading.ignore();
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				if (i < n - 1)
				{
					int n;
					getline(reading, nazv);
					record << nazv << endl;
					reading >> n;
					reading.ignore();
					record << n << endl;
					for (int i = 0; i < n; i++)
					{
						int n;
						getline(reading, nazv);
						record << nazv << endl;
						reading >> n;
						reading.ignore();
						record << n << endl;
						for (int i = 0; i < n; i++)
						{
							int n;
							int m;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							record << n << endl;
							reading >> m;
							reading.ignore();
							record << m << endl;
							for (int i = 0; i < n; i++)
							{
								getline(reading, nazv);
								record << nazv << endl;
								for (int i = 0; i < m; i++)
								{
									getline(reading, nazv);
									record << nazv << endl;
									reading >> ocen;
									record << ocen << endl;
									reading >> ocen;
									reading.ignore();
									record << ocen << endl;
								}
							}
						}
					}
				}
				else
				{
					int n;
					getline(reading, nazv);
					record << nazv << endl;
					reading >> n;
					reading.ignore();
					if (n == 0)
						record << n;
					else
						record << n << endl;
					for (int i = 0; i < n; i++)
					{
						if (i < n - 1)
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							record << n << endl;
							for (int i = 0; i < n; i++)
							{
								int n;
								int m;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								record << n << endl;
								reading >> m;
								reading.ignore();
								record << m << endl;
								for (int i = 0; i < n; i++)
								{
									getline(reading, nazv);
									record << nazv << endl;
									for (int i = 0; i < m; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										reading >> ocen;
										record << ocen << endl;
										reading >> ocen;
										reading.ignore();
										record << ocen << endl;
									}
								}
							}
						}
						else
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							if (n == 0)
								record << n;
							else
								record << n << endl;
							for (int i = 0; i < n; i++)
							{
								if (i < n - 1)
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									record << n << endl;
									reading >> m;
									reading.ignore();
									record << m << endl;
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											reading >> ocen;
											record << ocen << endl;
											reading >> ocen;
											reading.ignore();
											record << ocen << endl;
										}
									}
								}
								else
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									if (n == 0)
									{
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m;
									}
									else
									{
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m << endl;
									}
									for (int i = 0; i < n; i++)
									{
										if (i < n - 1)
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												reading >> ocen;
												record << ocen << endl;
												reading >> ocen;
												reading.ignore();
												record << ocen << endl;
											}
										}
										else
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												if (i < m - 1)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
												else
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout << "Данные успешно сохранены в файл " << full << endl;
			system("pause");
		}
		else
		{
			cout << "Ошибка открытия файла!\n";
			system("Pause");
		}
	}
	else
	{
		cout << "Ошибка открытия буферного файла!\n";
		system("Pause");
	}
	reading.close();
	record.close();
}
bool dataCleaning()
{
	bool clear = false;
	fstream _buf("Buffer.txt", ios::out);
	if (!_buf)
		cout << "Ошибка открытия буферного файла!" << endl;
	_buf.clear();
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;
	_buf.close();
	return clear;
}
void dataInitialization()
{
	ofstream _buf("Buffer.txt");
	if (!_buf)
	{
		cout << "\nОшибка создания буферного файла!!!" << endl;
		system("pause");
	}
	_buf.close();
}
void dataReading()
{
	system("cls");
	if (!fileVoid("Buffer.txt"))
	{
		int a;
		cout << "База данных уже загружена!" << endl;
		cout << "1.Загрузить другую БД 2.Выйти" << endl;
		cin >> a;
		if (a == 1)
		{
			fstream file("Buffer.txt", ios::out);
			file.clear();
			file.close();
			system("cls");
		}
		else if (a == 2)
		{
			return void();
		}
		else
		{
			while (a > 2 || a < 1)
			{
				cout << "Ошибка ввода!";
				cin >> a;
			}
			if (a == 2)
				return void();
			else
			{
				fstream file("Buffer.txt", ios::out);
				file.clear();
				file.close();
				system("cls");
			}
		}
	}
	string filename;
	cout << "Введите название файла(без разрешения .txt) из которого вы хотите взять данные: ";
	while (cin.get() != '\n');
	getline(cin, filename);
	string full;
	string txt = ".txt";
	full = filename + txt;
	if (!FileIsExist(full))
	{
		cout << "БД с такми названием нет!" << endl;
		system("pause");
		return void();
	}
	ifstream reading(full);
	if (fileVoid(full))
	{
		cout << "Файл пуст!" << endl;
		system("pause");
		return void();
	}
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string nazv;
			int ocen;
			int n;
			reading >> n;
			reading.ignore();
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				if (i<n-1)
				{
					int n;
					getline(reading, nazv);
					record << nazv << endl;
					reading >> n;
					reading.ignore();
					record << n << endl;
					for (int i = 0; i < n; i++)
					{
						int n;
						getline(reading, nazv);
						record << nazv << endl;
						reading >> n;
						reading.ignore();
						record << n << endl;
						for (int i = 0; i < n; i++)
						{
							int n;
							int m;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							record << n << endl;
							reading >> m;
							reading.ignore();
							record << m << endl;
							for (int i = 0; i < n; i++)
							{
								getline(reading, nazv);
								record << nazv << endl;
								for (int i = 0; i < m; i++)
								{
									getline(reading, nazv);
									record << nazv << endl;
									reading >> ocen;
									record << ocen << endl;
									reading >> ocen;
									reading.ignore();
									record << ocen << endl;
								}
							}
						}
					}
				}
				else
				{
					int n;
					getline(reading, nazv);
					record << nazv << endl;
					reading >> n;
					reading.ignore();
					if (n == 0)
						record << n;
					else
						record << n << endl;
					for (int i = 0; i < n; i++)
					{
						if (i< n-1)
						{ 
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							record << n << endl;
							for (int i = 0; i < n; i++)
							{
								int n;
								int m;
								getline(reading, nazv);
								record << nazv << endl;
								reading >> n;
								record << n << endl;
								reading >> m;
								reading.ignore();
								record << m << endl;
								for (int i = 0; i < n; i++)
								{
									getline(reading, nazv);
									record << nazv << endl;
									for (int i = 0; i < m; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										reading >> ocen;
										record << ocen << endl;
										reading >> ocen;
										reading.ignore();
										record << ocen << endl;
									}
								}
							}
						}
						else
						{
							int n;
							getline(reading, nazv);
							record << nazv << endl;
							reading >> n;
							reading.ignore();
							if (n == 0)
								record << n;
							else
								record << n << endl;
							for (int i = 0; i < n; i++)
							{
								if (i< n-1)
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									record << n << endl;
									reading >> m;
									reading.ignore();
									record << m << endl;
									for (int i = 0; i < n; i++)
									{
										getline(reading, nazv);
										record << nazv << endl;
										for (int i = 0; i < m; i++)
										{
											getline(reading, nazv);
											record << nazv << endl;
											reading >> ocen;
											record << ocen << endl;
											reading >> ocen;
											reading.ignore();
											record << ocen << endl;
										}
									}
								}
								else
								{
									int n;
									int m;
									getline(reading, nazv);
									record << nazv << endl;
									reading >> n;
									if (n == 0)
									{
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m;
									}
									else
									{
										record << n << endl;
										reading >> m;
										reading.ignore();
										record << m << endl;
									}
									for (int i = 0; i < n; i++)
									{
										if (i< n-1)
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												getline(reading, nazv);
												record << nazv << endl;
												reading >> ocen;
												record << ocen << endl;
												reading >> ocen;
												reading.ignore();
												record << ocen << endl;
											}
										}
										else
										{
											getline(reading, nazv);
											record << nazv << endl;
											for (int i = 0; i < m; i++)
											{
												if (i < m - 1)
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen << endl;
												}
												else
												{
													getline(reading, nazv);
													record << nazv << endl;
													reading >> ocen;
													record << ocen << endl;
													reading >> ocen;
													reading.ignore();
													record << ocen;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout << "Данные успешно считаны из файла " << full << endl;
			system("pause");
		}
		else
		{
			cout << "Ошибка открытия буферного файла!\n";
			system("Pause");
		}
	}
	else
	{
		cout << "Ошибка открытия файла!\n";
		system("Pause");
	}
	reading.close();
	record.close();
}
bool FileIsExist(string filePath)
{
	bool isExist = false;
	std::ifstream fin(filePath.c_str());
	if (fin.is_open())
		isExist = true;
	fin.close();
	return isExist;
}
bool fileVoid(string filename)
{
	fstream file(filename);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!\n";
		system("pause");
		return true;
	}
	else if (file.peek() == EOF)
		return true;
	file.close();
	return false;
}