% ������
clear p
clc
p = input('������ʿռ䣺');
p_log = log2(p);
H_p = (-1)*sum(p_log.*p);
H_p