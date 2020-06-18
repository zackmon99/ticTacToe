class Square
{
private:
    int m_row;
    int m_column;

    int m_state;
public:
    Square(int row, int column);
    int getRow();
    void setRow(int row);
    int getColumn();
    void setColumn(int column);
    void setRowColumn(int row, int column);
    int getState();
    void setState(int state);
    ~Square();
};



