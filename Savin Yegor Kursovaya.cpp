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
				cout << "���� ������� ��� �� �����?\n1.������� 2.�� �����\n" << endl;
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
						cout << "������ �����!\n";
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
				cout << " ����:\n";
				cout << "  1.����/��������\n";
				cout << "  2.���������� ������\n";
				cout << "  3.��������� ������\n";
				cout << "  4.�������� ������\n";
				cout << "  5.�����\n";
				cout << "  6.����������\n";   
				cout << "  7.�����\n\n";
			}
			if (meniu == 7)
			{
				system("cls");
				if (dataCleaning())
					cout << "������ �� ������ ��������!" << endl;
				else
					cout << "������ �� ������ �� �������!!!" << endl;
				cout << "������ ���������." << endl;
				break;
			}
		}
		else
		{
			cout << "������ �����! \n\n";
				return 0;
		}
		cout << "����: ";
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
		cout << "���� ������ ��� ���������!" << endl;
		cout << "1.������ ������ �� 2.�����" << endl;
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
				cout << "������ �����!";
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
	cout << "������� ����������� ����������: ";
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
				cout << "������� �������� ���������: ";
				while (cin.get() != '\n');
				getline(cin, inst);
				record << inst << endl;
				int m;
				cout << "������� ������ � ���� ���������? ";
				cin >> m;
				record << m << endl;
				for (int i = 0; i < m; i++)
				{
					int m;
					string kaf;
					cout << "������� �������� �������: ";
					while (cin.get() != '\n');
					getline(cin, kaf);
					record << kaf << endl;
					cout << "������� ����� � ���� �������? ";
					cin >> m;
					record << m << endl;
					for (int i = 0; i < m; i++)
					{
						int a;
						int m;
						string grupp;
						cout << "������� �������� ������: ";
						while (cin.get() != '\n');
						getline(cin, grupp);
						record << grupp << endl;
						cout << "������� ��������� � ���� ������? ";
						cin >> m;
						cout << "������� ����������� ��������� � ��������� ���� ������: ";
						cin >> a;
						if (a == 0)
						{
							cout << "������ �����!";
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
							cout << "������� �������� ��������: ";
							while (cin.get() != '\n');
							getline(cin, pred);
							predm[i] = pred;
							cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
							cin >> a;
							a--;
							kurs[i] = a;
						}
						for (int i = 0; i < m; i++)
						{
							string fio;
							cout << "������� ��� ��������: ";
							while (cin.get() != '\n');
							getline(cin, fio);
							record << fio << endl;
							for (int i = 0; i < a; i++)
							{
								int ocen;
								cout << "������ �� �������� " << predm[i] << ": ";
								record << predm[i] << endl;
								cin >> ocen;
								record << ocen << endl;
								if (kurs[i] == 0)
								{
									int ocen;
									cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
				cout << "\n�� ������� ��������� ������ �� ���������!" << endl;
				system("Pause");
				system("cls");
			}
			else
			{
			string inst;
			cout << "������� �������� ���������: ";
			while (cin.get() != '\n');
			getline(cin, inst);
			record << inst << endl;
			int m;
			cout << "������� ������ � ���� ���������? ";
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
					cout << "������� �������� �������: ";
					while (cin.get() != '\n');
					getline(cin, kaf);
					record << kaf << endl;
					cout << "������� ����� � ���� �������? ";
					cin >> m;
					record << m << endl;
					for (int i = 0; i < m; i++)
					{
						int a;
						int m;
						string grupp;
						cout << "������� �������� ������: ";
						while (cin.get() != '\n');
						getline(cin, grupp);
						record << grupp << endl;
						cout << "������� ��������� � ���� ������? ";
						cin >> m;
						cout << "������� ����������� ��������� � ��������� ���� ������: ";
						cin >> a;
						if (a == 0)
						{
							cout << "������ �����!";
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
							cout << "������� �������� ���������: ";
							while (cin.get() != '\n');
							getline(cin, pred);
							predm[i] = pred;
							cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
							cin >> a;
							a--;
							kurs[i] = a;
						}
						for (int i = 0; i < m; i++)
						{
							string fio;
							cout << "������� ��� ��������: ";
							while (cin.get() != '\n');
							getline(cin, fio);
							record << fio << endl;
							for (int i = 0; i < a; i++)
							{
								int ocen;
								cout << "������ �� �������� " << predm[i] << ": ";
								record << predm[i] << endl;
								cin >> ocen;
								record << ocen << endl;
								if (kurs[i] == 0)
								{
									int ocen;
									cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
					cout << "������� �������� �������: ";
					while (cin.get() != '\n');
					getline(cin, kaf);
					record << kaf << endl;
					cout << "������� ����� � ���� �������? ";
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
							cout << "������� �������� ������: ";
							while (cin.get() != '\n');
							getline(cin, grupp);
							record << grupp << endl;
							cout << "������� ��������� � ���� ������? ";
							cin >> m;
							cout << "������� ����������� ��������� � ��������� ���� ������: ";
							cin >> a;
							if (a == 0)
							{
								cout << "������ �����!";
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
								cout << "������� �������� ���������: ";
								while (cin.get() != '\n');
								getline(cin, pred);
								predm[i] = pred;
								cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
								cin >> a;
								a--;
								kurs[i] = a;
							}
							for (int i = 0; i < m; i++)
							{
								string fio;
								cout << "������� ��� ��������: ";
								while (cin.get() != '\n');
								getline(cin, fio);
								record << fio << endl;
								for (int i = 0; i < a; i++)
								{
									int ocen;
									cout << "������ �� �������� " << predm[i] << ": ";
									record << predm[i] << endl;
									cin >> ocen;
									record << ocen << endl;
									if (kurs[i] == 0)
									{
										int ocen;
										cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
							cout << "������� �������� ������: ";
							while (cin.get() != '\n');
							getline(cin, grupp);
							record << grupp << endl;
							cout << "������� ��������� � ���� ������? ";
							cin >> m;
							cout << "������� ����������� ��������� � ��������� ���� ������: ";
							cin >> a;
							if (a == 0)
							{
								cout << "������ �����!";
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
								cout << "������� �������� ���������: ";
								while (cin.get() != '\n');
								getline(cin, pred);
								predm[i] = pred;
								cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
								cin >> a;
								a--;
								kurs[i] = a;
							}
							for (int i = 0; i < m; i++)
							{
								if (i < m - 1)
								{
									string fio;
									cout << "������� ��� ��������: ";
									while (cin.get() != '\n');
									getline(cin, fio);
									record << fio << endl;
									for (int i = 0; i < a; i++)
									{
										int ocen;
										cout << "������ �� �������� " << predm[i] << ": ";
										record << predm[i] << endl;
										cin >> ocen;
										record << ocen << endl;
										if (kurs[i] == 0)
										{
											int ocen;
											cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
									cout << "������� ��� ��������: ";
									while (cin.get() != '\n');
									getline(cin, fio);
									record << fio << endl;
									for (int i = 0; i < a; i++)
									{
										if (i < a - 1)
										{
											int ocen;
											cout << "������ �� �������� " << predm[i] << ": ";
											record << predm[i] << endl;
											cin >> ocen;
											record << ocen << endl;
											if (kurs[i] == 0)
											{
												int ocen;
												cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
											cout << "������ �� �������� " << predm[i] << ": ";
											record << predm[i] << endl;
											cin >> ocen;
											record << ocen << endl;
											if (kurs[i] == 0)
											{
												int ocen;
												cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
			cout << "\n�� ������� ��������� ������ �� ���������!" << endl;
			system("Pause");
			system("cls");
			}
		}
		cout << "�� ������� ������� ��!" << endl;
		system("Pause");
		record.close();
	}
	else
	{
		cout << "������ �������� �����!" << endl;
		system("pause");
	}
}
void Print()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "����� ����!" << endl;
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
		cout << "| ���������� ����������: " << p <<"                                                                                        |"<< endl;
		cout << " -----------------------------------------------------------------------------------------------------------------\n" << endl;
		for (int i = 0; i < p; i++)
		{
			cout << "__________________________________________________________________________________________________________________________________" << endl;
			int n;
			cout << "������ � ��������� �" << i + 1 << endl;
			getline(reading, nazv);
			cout << "�������� ���������: " <<  nazv << endl;
			reading >> n;
			reading.ignore();
			cout << "���������� ������ � ��������� " << nazv << ": "<<n<<endl;
			for (int i = 0; i < n; i++)
			{
				cout << "\t=========================================================================================================================" << endl;
				int l;
				cout << "\t������ � ������� �" << i + 1 << endl;
				getline(reading, nazv);
				cout << "\t�������� �������: " << nazv << endl;
				reading >> l;
				reading.ignore();
				cout << "\t���������� ����� � ������� " << nazv << ": " << l << endl;
				for (int i = 0; i < l; i++)
				{
					int k;
					int m;
					cout << "\t\t----------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t\t������ � ������ �" << i + 1 << endl;
					getline(reading, nazv);
					cout << "\t\t�������� ������: " << nazv << endl;
					reading >> k;
					cout << "\t\t���������� ��������� � ������ " << nazv << ": " << k << endl<<endl;
					reading >> m;
					reading.ignore();
					for (int i = 0; i < k; i++)
					{
						cout << "\t\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
						cout << "\t\t\t+ ������ � �������� �" << i + 1;
						if (i>9)
							cout<< "                                                                                 +" << endl;
						else
							cout<< "                                                                                +" << endl;
						getline(reading, nazv);
						cout << "\t\t\t+  ��� ��������: " << nazv;
						space(nazv, 85);
						cout << "+" << endl;
						cout << "\t\t\t+  ������ �������� " << "                                                                                   +" << endl;
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
								cout << "|  "  << "\t� ����� �������� ��� �������� ������          +" << endl;
							}
							else
							{
								space(nazv,45);
								cout << "|  " << "\t������ �� �������� ������ �� ����� ��������:" << ocen <<" +"<<endl;
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
		cout << "������ �������� �����!" << endl;
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
		cout << "����� ����!" << endl;
		system("pause");
		return void(); 
	}
	if (AmountOfData() == 0)
	{
		cout << "������ ��� ��������� ������ ���!" << endl;
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
		cout << "\n1.�������� 2.�����\n";
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
					cout << "�������� ����� ��������, ������� ������ ��������: ";
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
								cout << "������� ����� �������� ���������" << endl;
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
						cout << "�� ������� �������� ������!" << endl;
						system("pause");
					}
					else
					{
						cout << "�������� � ����� ������� �� ����������!" << endl;
						system("Pause");
						return void();
					}
					reading.close();
					record.close();
					remove("Buffer_.txt");
				}
				else
				{
					cout << "������ �������� ��������� �����!\n";
					system("Pause");
				}
			}
			else
			{
				cout << "������ �������� ��������� �����!\n";
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
				cout << "�������� ����� ���������: ";
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
						cout << "������ ��� ��������� ������ ���!" << endl;
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
				cout << "������ �������� ��������� �����!\n";
				system("Pause");
			}
			cout << "\n1.�������� 2.�����\n";
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
						cout << "�������� ����� ��������, ������� ������ ��������: ";
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
										cout << "������� ����� �������� �������: ";
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
											cout << "������� ����� �������� �������: ";
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
											cout << "������� ����� �������� �������: ";
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
						cout << "�� ������� �������� ������!" << endl;
						system("pause");
						reading.close();
						record.close();
						remove("Buffer_.txt");
					}
					else
					{
						cout << "������ �������� ��������� �����!\n";
						system("Pause");
					}
				}
				else
				{
					cout << "������ �������� ��������� �����!\n";
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
					cout << "�������� ����� �������: ";
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
								cout << "������ ��� ��������� ������ ���!" << endl;
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
					cout << "������ �������� ��������� �����!\n";
					system("Pause");
				}
				cout << "\n1.�������� 2.�����\n";
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
							cout << "�������� ����� ��������, ������� ������ ��������: ";
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
												cout << "������� ����� �������� ������: ";
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
													cout << "������� ����� �������� ������: ";
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
														cout << "������� ����� �������� ������: ";
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
														cout << "������� ����� �������� ������: ";
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
							cout << "�� ������� �������� ������!" << endl;
							system("pause");
							reading.close();
							record.close();
							remove("Buffer_.txt");
						}
						else
						{
							cout << "������ �������� ��������� �����!\n";
							system("Pause");
						}
					}
					else
					{
						cout << "������ �������� ��������� �����!\n";
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
						cout << "�������� ����� ������: ";
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
										cout << "������ ��� ��������� ������ ���!" << endl;
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
						cout << "������ �������� ��������� �����!\n";
						system("Pause");
					}
					cout << "\n1.�������� 2.�����\n";
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
								cout << "�������� ����� ��������, ������� ������ ��������: ";
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
														cout << "������� ����� ��� ��������: ";
														while (cin.get() != '\n');
														getline(cin, nazv);
														record << nazv << endl;
														getline(reading, nazv);
														for (int i = 0; i < m; i++)
														{
															getline(reading, nazv);
															record << nazv << endl;
															cout << "������ �� �������� " << nazv << ": ";
															cin >> ocen;
															record << ocen << endl;
															reading >> ocen;
															reading >> ocen;
															reading.ignore();
															if (ocen != 0)
															{
																cout << "������ �� �������� �� �������� " << nazv << ": ";
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
															cout << "������� ����� ��� ��������: ";
															while (cin.get() != '\n');
															getline(cin, nazv);
															record << nazv << endl;
															getline(reading, nazv);
															for (int i = 0; i < m; i++)
															{
																getline(reading, nazv);
																record << nazv << endl;
																cout << "������ �� �������� " << nazv << ": ";
																cin >> ocen;
																record << ocen << endl;
																reading >> ocen;
																reading >> ocen;
																reading.ignore();
																if (ocen != 0)
																{
																	cout << "������ �� �������� �� �������� " << nazv << ": ";
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
																cout << "������� ����� ��� ��������: ";
																while (cin.get() != '\n');
																getline(cin, nazv);
																record << nazv << endl;
																getline(reading, nazv);
																for (int i = 0; i < m; i++)
																{
																	getline(reading, nazv);
																	record << nazv << endl;
																	cout << "������ �� �������� " << nazv << ": ";
																	cin >> ocen;
																	record << ocen << endl;
																	reading >> ocen;
																	reading >> ocen;
																	reading.ignore();
																	if (ocen != 0)
																	{
																		cout << "������ �� �������� �� �������� " << nazv << ": ";
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
																	cout << "������� ����� ��� ��������: ";
																	while (cin.get() != '\n');
																	getline(cin, nazv);
																	record << nazv << endl;
																	getline(reading, nazv);
																	for (int i = 0; i < m; i++)
																	{
																		getline(reading, nazv);
																		record << nazv << endl;
																		cout << "������ �� �������� " << nazv << ": ";
																		cin >> ocen;
																		record << ocen << endl;
																		reading >> ocen;
																		reading >> ocen;
																		reading.ignore();
																		if (ocen != 0)
																		{
																			cout << "������ �� �������� �� �������� " << nazv << ": ";
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
																	cout << "������� ����� ��� ��������: ";
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
																			cout << "������ �� �������� " << nazv << ": ";
																			cin >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading >> ocen;
																			reading.ignore();
																			if (ocen != 0)
																			{
																				cout << "������ �� �������� �� �������� " << nazv << ": ";
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
																			cout << "������ �� �������� " << nazv << ": ";
																			cin >> ocen;
																			record << ocen << endl;
																			reading >> ocen;
																			reading >> ocen;
																			reading.ignore();
																			if (ocen != 0)
																			{
																				cout << "������ �� �������� �� �������� " << nazv << ": ";
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
								cout << "�� ������� �������� ������!" << endl;
								system("pause");
								reading.close();
								record.close();
								remove("Buffer_.txt");
							}
							else
							{
								cout << "������ �������� ��������� �����!\n";
								system("Pause");
							}
						}
						else
						{
							cout << "������ �������� ��������� �����!\n";
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
					cout << "������ �����!" << endl;
					system("pause");
					return void();
				}
			}
			else
			{
			cout << "������ �����!" << endl;
			system("pause");
			return void();
			}
		}
		else
		{
		cout << "������ �����!" << endl;
		system("pause");
		return void();
		}
	}
	else
	{
		cout << "������ �������� ��������� �����!\n";
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
			cout << "������ �������� ������� ��������� �����!";
			system("pause");
		}
	}
	else
	{
		cout << "������ �������� ��������� �����!";
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
		cout << "����� ����!" << endl;
		system("pause");
		return void();
	}
	if (AmountOfData() == 0)
	{
		cout << "������ ��� �������� ������ ���!" << endl;
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
		cout << "\n1.������� �������� ��� �������� 2.�����\n";
		cin >> a;
		if (a == 1)
		{
			if (AmountOfData() == 1)
			{
				int a;
				cout << "� ������ ������ ���� ��������. ������ ������� ���?\n1.�� 2.���\n";
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
						cout << "������ �����!";
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
					cout << "�������� ����� ��������, ������� ������ �������: ";
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
						cout << "�� ������� �������� ������!" << endl;
						system("pause");
					}
					else
					{
						cout << "�������� � ����� ������� �� ����������!" << endl;
						system("Pause");
						return void();
					}

					reading.close();
					record.close();
					remove("Buffer_.txt");
				}
				else
				{
					cout << "������ �������� ��������� �����!\n";
					system("Pause");
				}
			}
			else
			{
				cout << "������ �������� ��������� �����!\n";
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
				cout << "�������� ����� ���������: ";
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
						cout<<"������ ��� �������� ������ ���!" << endl;
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
				cout << "������ �������� ��������� �����!\n";
				system("Pause");
			}
			cout << "\n1.������� ������� ��� �������� 2.�����\n";
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
						cout << "�������� ����� ��������, ������� ������ �������: ";
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
						cout << "�� ������� ������� ������!" << endl;
						system("pause");					
						reading.close();
						record.close();
						remove("Buffer_.txt");
					}
					else
					{
						cout << "������ �������� ��������� �����!\n";
						system("Pause");
					}
				}
				else
				{
					cout << "������ �������� ��������� �����!\n";
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
					cout << "�������� ����� �������: ";
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
								cout << "������ ��� �������� ������ ���!" << endl;
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
					cout << "������ �������� ��������� �����!\n";
					system("Pause");
				}
				cout << "\n1.������� ������ ��� �������� 2.�����\n";
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
							cout << "�������� ����� ��������, ������� ������ �������: ";
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
							cout << "�� ������� ������� ������!" << endl;
							system("pause");
							reading.close();
							record.close();
							remove("Buffer_.txt");
						}
						else
						{
							cout << "������ �������� ��������� �����!\n";
							system("Pause");
						}
					}
					else
					{
						cout << "������ �������� ��������� �����!\n";
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
						cout << "�������� ����� ������: ";
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
										cout << "������ ��� �������� ������ ���!" << endl;
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
						cout << "������ �������� ��������� �����!\n";
						system("Pause");
					}
					cout << "1.������� �������� ��� �������� 2.�����\n";
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
								cout << "�������� ����� ��������, ������� ������ �������: ";
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
								cout << "�� ������� ������� ������!" << endl;
								system("pause");
								reading.close();
								record.close();
								remove("Buffer_.txt");
							}
							else
							{
								cout << "������ �������� ��������� �����!\n";
								system("Pause");
							}
						}
						else
						{
							cout << "������ �������� ��������� �����!\n";
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
					cout << "������ �����!" << endl;
					system("pause");
					return void();
				}
			}
			else
			{
				cout << "������ �����!" << endl;
				system("pause");
				return void();
			}
		}
		else
		{
			cout << "������ �����!" << endl;
			system("pause");
			return void();
		}
	}
	else
	{
		cout << "������ �������� ��������� �����!\n";
		system("Pause");
	}
}
void dataAdd()
{
	system("cls");
	if (fileVoid("Buffer.txt"))
	{
		cout << "����� ����!" << endl;
		system("pause");
		return void();
	}
	if (AmountOfData() == 0)
	{
		int a;
		cout << "� ���� ������ ��� �� ������ ���������\n1.�������� 2.�����" << endl;
		cin >> a;
		if (a == 1)
		{
			string nazv;
			ofstream record("Buffer.txt", ios::out);
			record << 1 << endl;
			cout << "������� �������� ���������: ";
			while (cin.get() != '\n');
			getline(cin, nazv);
			record << nazv<<endl;
			record << 0;
			record.close();
			cout << "�� ������� �������� ���������!";
			return void();
		}
		else if (a==2)
			return void();
		else
		{
			cout << "������ �����!";
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
		cout << "\n1.�������� �������� 2.�����\n";
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
					cout << "������� �������� ���������: ";
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
					cout <<"�� ������� �������� ��������!\n";
					system("pause");
					reading.close();
					record.close();
					remove("Buffer_.txt");
				}
				else
				{
					cout << "������ �������� ��������� �����!\n";
					system("Pause");
				}
			}
			else
			{
				cout << "������ �������� ��������� �����!\n";
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
				cout << "�������� ����� ���������: ";
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
				cout << "������ �������� ��������� �����!\n";
				system("Pause");
			}
			if (pi == 0)
			{
				int vopr;
				system("cls");
				cout << "� ��������� ��� ������\n1.�������� 2.�����\n";
				cin >> vopr;
				if (vopr == 2)
				{
					reading.close();
					return void();
				}
				else if (vopr != 1)
				{
					cout << "������ �����!\n";
					system("pause");
					reading.close();
					return void();
				}
				else
					a = 1;
			}
			else if (pi == 1)
			{
				cout << "\n1.�������� ������� 2.�����\n";
				cin >> a;
			}
			else
			{
				cout << "������!!!";
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
									cout << "������� �������� �������: ";
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
									cout << "������� �������� �������: ";
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
											cout << "������� �������� �������: ";
											while (cin.get() != '\n');
											getline(cin, kaf);
											record << endl<<kaf << endl;
											record << 0;
										}
									}
								}
							}
						}
						cout << "�� ������� �������� �������!" << endl;
						system("pause");
						reading.close();
						record.close();
						remove("Buffer_.txt");
					}
					else
					{
						cout << "������ �������� ��������� �����!\n";
						system("Pause");
					}
				}
				else
				{
					cout << "������ �������� ��������� �����!\n";
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
					cout << "�������� ����� �������: ";
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
					cout << "������ �������� ��������� �����!\n";
					system("Pause");
				}
				if (pi == 0)
				{
					int vopr;
					system("cls");
					cout << "� ������� ��� �����\n1.�������� 2.�����\n";
					cin >> vopr;
					if (vopr == 2)
					{
						reading.close();
						return void();
					}
					else if (vopr != 1)
					{
						cout << "������ �����!\n";
						system("pause");
						reading.close();
						return void();
					}
					else
						a = 1;
				}
				else if (pi == 1)
				{
					cout << "\n1.�������� ������ 2.�����\n";
					cin >> a;
				}
				else
				{
				cout << "������!!!";
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
											cout << "������� �������� ������: ";
											while (cin.get() != '\n');
											getline(cin, gr);
											cout << "������� ����������� ��������� � ������: ";
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
												cout << "������� �������� ������: ";
												while (cin.get() != '\n');
												getline(cin, gr);
												cout << "������� ����������� ��������� � ������: ";
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
												cout << "������� �������� ������: ";
												while (cin.get() != '\n');
												getline(cin, gr);
												cout << "������� ����������� ��������� � ������: ";
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
														cout << "������� �������� ������: ";
														while (cin.get() != '\n');
														getline(cin, gr);
														cout << "������� ����������� ��������� � ������: ";
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
							cout << "�� ������� �������� ������!" << endl;
							system("pause");
							reading.close();
							record.close();
							remove("Buffer_.txt");
						}
						else
						{
							cout << "������ �������� ��������� �����!\n";
							system("Pause");
						}
					}
					else
					{
						cout << "������ �������� ��������� �����!\n";
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
						cout << "�������� ����� ������: ";
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
						cout << "������ �������� ��������� �����!\n";
						system("Pause");
					}
					if (pi == 0)
					{
						int vopr;
						system("cls");
						cout << "� ������ ��� ���������\n1.�������� 2.�����\n";
						cin >> vopr;
						if (vopr == 2)
						{
							reading.close();
							return void();
						}
						else if (vopr != 1)
						{
							cout << "������ �����!\n";
							system("pause");
							reading.close();
							return void();
						}
						else
						{
							cout << "��������� ������ ���������, ����������\n\n";
							system("pause");
							a = 1;
						}
					}
					else if (pi==1)
					{
						cout << "\n1.�������� �������� 2.�����\n";
						cin >> a;
					}
					else
					{
						cout << "������!!!";
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
														cout << "������� �������� ��������: ";
														while (cin.get() != '\n');
														getline(cin, pred);
														predm[i] = pred;
														cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
														cin >> a;
														a--;
														kurs[i] = a;
													}
													string fio;
													cout << "������� ��� ��������: ";
													while (cin.get() != '\n');
													getline(cin, fio);
													record << fio << endl;
													for (int i = 0; i < m; i++)
													{
														int ocen;
														cout << "������ �� �������� " << predm[i] << ": ";
														record << predm[i] << endl;
														cin >> ocen;
														record << ocen << endl;
														if (kurs[i] == 0)
														{
															int ocen;
															cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
														cout << "������� ��� ��������: ";
														while (cin.get() != '\n');
														getline(cin, fio);
														record << fio << endl;
														for (int i = 0; i < m; i++)
														{
															int ocen;
															cout << "������ �� �������� " << predm[i] << ": ";
															record << predm[i] << endl;
															cin >> ocen;
															record << ocen << endl;
															if (kurs[i] !=0)
															{
																int ocen;
																cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
															cout << "������� �������� ��������: ";
															while (cin.get() != '\n');
															getline(cin, pred);
															predm[i] = pred;
															cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
															cin >> a;
															a--;
															kurs[i] = a;
														}
														string fio;
														cout << "������� ��� ��������: ";
														while (cin.get() != '\n');
														getline(cin, fio);
														record << fio << endl;
														for (int i = 0; i < m; i++)
														{
															int ocen;
															cout << "������ �� �������� " << predm[i] << ": ";
															record << predm[i] << endl;
															cin >> ocen;
															record << ocen << endl;
															if (kurs[i] == 0)
															{
																int ocen;
																cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
															cout << "������� ��� ��������: ";
															while (cin.get() != '\n');
															getline(cin, fio);
															record << fio << endl;
															for (int i = 0; i < m; i++)
															{
																int ocen;
																cout << "������ �� �������� " << predm[i] << ": ";
																record << predm[i] << endl;
																cin >> ocen;
																record << ocen << endl;
																if (kurs[i] != 0)
																{
																	int ocen;
																	cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
																cout << "������� �������� ��������: ";
																while (cin.get() != '\n');
																getline(cin, pred);
																predm[i] = pred;
																cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
																cin >> a;
																a--;
																kurs[i] = a;
															}
															string fio;
															cout << "������� ��� ��������: ";
															while (cin.get() != '\n');
															getline(cin, fio);
															record << fio << endl;
															for (int i = 0; i < m; i++)
															{
																int ocen;
																cout << "������ �� �������� " << predm[i] << ": ";
																record << predm[i] << endl;
																cin >> ocen;
																record << ocen << endl;
																if (kurs[i] == 0)
																{
																	int ocen;
																	cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
																cout << "������� ��� ��������: ";
																while (cin.get() != '\n');
																getline(cin, fio);
																record << fio << endl;
																for (int i = 0; i < m; i++)
																{
																	int ocen;
																	cout << "������ �� �������� " << predm[i] << ": ";
																	record << predm[i] << endl;
																	cin >> ocen;
																	record << ocen << endl;
																	if (kurs[i] != 0)
																	{
																		int ocen;
																		cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
																cout << "������� �������� ��������: ";
																while (cin.get() != '\n');
																getline(cin, pred);
																predm[i] = pred;
																cout << "���� �� �������� �� ����� ��������?\n1.�� 2.��� ";
																cin >> a;
																a--;
																kurs[i] = a;
															}
															string fio;
															cout << "������� ��� ��������: ";
															while (cin.get() != '\n');
															getline(cin, fio);
															record << fio << endl;
															for (int i = 0; i < m; i++)
															{
																if (i < m - 1)
																{
																	int ocen;
																	cout << "������ �� �������� " << predm[i] << ": ";
																	record << predm[i] << endl;
																	cin >> ocen;
																	record << ocen << endl;
																	if (kurs[i] == 0)
																	{
																		int ocen;
																		cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
																	cout << "������ �� �������� " << predm[i] << ": ";
																	record << predm[i] << endl;
																	cin >> ocen;
																	record << ocen << endl;
																	if (kurs[i] == 0)
																	{
																		int ocen;
																		cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
																			cout << "������� ��� ��������: ";
																			while (cin.get() != '\n');
																			getline(cin, fio);
																			record << endl << fio << endl;
																			for (int i = 0; i < m; i++)
																			{
																				if (i < m - 1)
																				{
																					int ocen;
																					cout << "������ �� �������� " << predm[i] << ": ";
																					record << predm[i] << endl;
																					cin >> ocen;
																					record << ocen << endl;
																					if (kurs[i] != 0)
																					{
																						int ocen;
																						cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
																					cout << "������ �� �������� " << predm[i] << ": ";
																					record << predm[i] << endl;
																					cin >> ocen;
																					record << ocen << endl;
																					if (kurs[i] != 0)
																					{
																						int ocen;
																						cout << "������ �� �������� �� �������� " << predm[i] << ": ";
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
								cout << "�� ������� �������� ��������!" << endl;
								system("pause");
								reading.close();
								record.close();
								remove("Buffer_.txt");
							}
							else
							{
								cout << "������ �������� ��������� �����!\n";
								system("Pause");
							}
						}
						else
						{
							cout << "������ �������� ��������� �����!\n";
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
					cout << "������ �����!" << endl;
					system("pause");
					return void();
				}
			}
			else
			{
				cout << "������ �����!" << endl;
				system("pause");
				return void();
			}
		}
		else
		{
			cout << "������ �����!" << endl;
			system("pause");
			return void();
		}
	}
	else
	{
		cout << "������ �������� ��������� �����!\n";
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
		cout << "������ �������� �����!" << endl;
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
		cout << "����� ����!" << endl;
		system("pause");
		return void();
	}
	ifstream reading("Buffer.txt");
	string filename;
	cout << "������� �������� �����(��� ���������� .txt), � ������� �� ������ ��������� ������: ";
	while (cin.get() != '\n');
	getline(cin, filename);
	string full;
	string txt = ".txt";
	full = filename + txt;
	while (FileIsExist(full))
	{
		cout << "���� � ����� ��������� ��� ����������!\n";
		cout << "����������, ����� ������ ��� �����: ";
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
			cout << "������ ������� ��������� � ���� " << full << endl;
			system("pause");
		}
		else
		{
			cout << "������ �������� �����!\n";
			system("Pause");
		}
	}
	else
	{
		cout << "������ �������� ��������� �����!\n";
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
		cout << "������ �������� ��������� �����!" << endl;
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
		cout << "\n������ �������� ��������� �����!!!" << endl;
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
		cout << "���� ������ ��� ���������!" << endl;
		cout << "1.��������� ������ �� 2.�����" << endl;
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
				cout << "������ �����!";
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
	cout << "������� �������� �����(��� ���������� .txt) �� �������� �� ������ ����� ������: ";
	while (cin.get() != '\n');
	getline(cin, filename);
	string full;
	string txt = ".txt";
	full = filename + txt;
	if (!FileIsExist(full))
	{
		cout << "�� � ����� ��������� ���!" << endl;
		system("pause");
		return void();
	}
	ifstream reading(full);
	if (fileVoid(full))
	{
		cout << "���� ����!" << endl;
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
			cout << "������ ������� ������� �� ����� " << full << endl;
			system("pause");
		}
		else
		{
			cout << "������ �������� ��������� �����!\n";
			system("Pause");
		}
	}
	else
	{
		cout << "������ �������� �����!\n";
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
		cout << "������ �������� �����!\n";
		system("pause");
		return true;
	}
	else if (file.peek() == EOF)
		return true;
	file.close();
	return false;
}