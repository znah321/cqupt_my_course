clear;clc
F = input("�����ۻ��ֲ�����F��");
L = input("�������ֳ���L��");
sum = 0;
for i = 1:length(L)
    for j = 1:L(i)
        if floor(F(i)/2^(-j)) == 0
            fprintf("%c",num2str(0));
        else
            fprintf("%c",num2str(1));
        end
        F(i) = mod(F(i),2^(-j));
    end
    fprintf("\n");
end