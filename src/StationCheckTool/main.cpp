#include "stationrobottool.h"
#include <QtWidgets/QApplication>
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include "qsqldatabase.h"
#include "qsqlerror.h"
extern std::string GetExePath(void);
std::string db_user_;
std::string db_pass_;
std::string db_port_;
std::string db_host_;
std::string db_name_;
void ReadDatabaseConfig(std::string file_path)
{
	rapidxml::file<> xml_file(file_path.c_str());
	rapidxml::xml_document<> document;
	document.parse<0>(xml_file.data());

	rapidxml::xml_node<>* root;
	root = document.first_node();
	if (root == NULL) {
		return;
	}
	while (root)
	{
		rapidxml::xml_node<>* node = root->first_node();

		while (node)
		{
			if (strcmp(node->name(), "DataBaseInfo") == 0)
			{
				rapidxml::xml_node<>* tcpinfo_node = node->first_node();
				rapidxml::xml_attribute<>* attr = tcpinfo_node->first_attribute();
				while (attr)
				{
					if (strcmp(attr->name(), "db_user") == 0)
					{
						db_user_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_host") == 0)
					{
						db_host_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_port") == 0)
					{
						db_port_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_name") == 0)
					{
						db_name_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_pass") == 0)
					{
						db_pass_ = attr->value();
					}
					attr = attr->next_attribute();
				}
			}
			node = node->next_sibling();
		}

		root = root->next_sibling();
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication::addLibraryPath("./plugins");
	QApplication a(argc, argv);

	std::string file_path = GetExePath();
	file_path = file_path + "\\etc\\ConfigInfo.xml";

	ReadDatabaseConfig(file_path);
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(QString::fromStdString(db_host_));
	db.setDatabaseName(QString::fromStdString(db_name_));
	db.setPort(atoi(db_port_.c_str()));
	db.setUserName(QString::fromStdString(db_user_));
	db.setPassword(QString::fromStdString(db_pass_));
	bool ok = db.open();
	if (ok)
	{
		QMessageBox::information(NULL, "数据库提示", "连接数据库成功");
	}
	else
	{
		QMessageBox::information(NULL, "数据库提示", "连接数据库失败: " + db.lastError().text());
		return -1;
	}
	StationRobotTool w;
	w.setFixedSize(1300, 850);
	w.show();
	return a.exec();
}
