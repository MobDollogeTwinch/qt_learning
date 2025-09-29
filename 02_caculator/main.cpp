#include <qapplication.h>
#include <qcontainerfwd.h>
#include <qgridlayout.h>
#include <qlineedit.h>
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qwidget.h>

class MainWindow : public QMainWindow {
  QLineEdit *m_line;
  bool hasDot = false;

  enum Operator {
    None, Plus, Minus, Multiply, Divide
  };

public:
  explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
    setWindowTitle("计算机");
    setCentralWidget(new QWidget);
    QGridLayout *layout = new QGridLayout;
    centralWidget()->setLayout(layout);

    m_line = new QLineEdit;
    m_line->setText("0");
    layout->addWidget(m_line, 0, 0, 1, 4);

    for (int i = 1; i <= 9; ++i) {
      QPushButton *button = new QPushButton;
      button->setText(QString::number(i));
      layout->addWidget(button, (i - 1) / 3 + 1, (i - 1) % 3);

      connect(button, &QPushButton::clicked, this, [this, i] {
        QString text = m_line->text();
        if (text.size() == 1 && text[0] == '0') {
          text.remove(text.size() - 1, 1);
        }
        text += QString::number(i);
        m_line->setText(text);
      });
    }

    {
      QPushButton *button = new QPushButton;
      button->setText(".");
      layout->addWidget(button, 4, 0);

      connect(button, &QPushButton::clicked, this, [this] {
        if (!hasDot) {
          QString text = m_line->text();
          text += ".";
          hasDot = true;
          m_line->setText(text);
        }
      });
    }

    {
      QPushButton *button = new QPushButton;
      button->setText("0");
      layout->addWidget(button, 4, 1);

      connect(button, &QPushButton::clicked, this, [this] {
        QString text = m_line->text();
        if (text.size() == 1 && text[0] == '0') {
          return;
        }
        text += "0";
        m_line->setText(text);
      });
    }

    {
      QPushButton *button = new QPushButton;
      button->setText("<");
      layout->addWidget(button, 4, 2);

      connect(button, &QPushButton::clicked, this, [this] {
        QString text = m_line->text();
        if (!text.isEmpty()) {
          if(text[text.size() - 1] == '.' && hasDot) {
            hasDot = false;
          }
          text.remove(text.size() - 1, 1);
        }
        if (text.isEmpty()) {
          text = "0";
        }
        m_line->setText(text);
      });
    }
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow _;
  _.show();
  return app.exec();
}