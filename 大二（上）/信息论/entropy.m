% 计算熵
clear p
clc
p = input('输入概率空间：');
p_log = log2(p);
H_p = (-1)*sum(p_log.*p);
H_p