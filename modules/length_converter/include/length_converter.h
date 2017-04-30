// Copyright 2017 Tarasov Oleg

/* 
�������������:
Length length(LENGTH_LYPE in_type, double value);
double converted_val = length.ConverTo(LENGTH_LYPE out_type);

LENGTH_LYPE in_type - ������� ������� ���������
double val - ������� ��������
out_type - �������� ������� ���������
*/


#ifndef _LENGTH_CONVERTER_H_
#define _LENGTH_CONVERTER_H_

enum LENGTH_TYPE {
    /* ����������� ������� ��������� */
    MICROMETRE,     // ��������� = 0.000001 �����
    MILLIMETRE,     // ��������� = 0.001 �����
    CENTIMETRE,     // ��������� = 0.01 �����
    DECIMETRE,      // �������� = 0.1 �����
    METRE,          // ����
    KILOMETRE,      // �������� = 1000 ������

    /* ���������� ������� ��� */
    INCH,           // ���� = 2.54 ��
    HAND,           // ���� = 10.16 ��
    LINK,           // ���� = 20.1168 ��
    FOOT,           // ��� = 30.48 ��
    YARD,           // ��� = 91.44 ��
    ROD,            // ���/���� = 5.0292 �
    CHAIN,          // ���� = 20.1168 �
    FURHLONG,       // ������� = 201.16 �
    MILE,           // ���� = 1,609344 ��
    LEAGUE          // ���� = 4,828032 ��
};


class Length {
public:
    Length(LENGTH_TYPE type, double value);
    double ConvertTo(LENGTH_TYPE type) const;
    
private:
    double length_sm; // ����� � �����������
    double GetConvertCoef(LENGTH_TYPE type) const;
};

#endif