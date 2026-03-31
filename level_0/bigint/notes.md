this nasty calc only works because the whole thing is in reverse, so
when we had a number like "99" with "01" we got 10 / 10 = 1 and 10 % 10 = 0
the current unit is 0 because is 10 reverse and the decimal is stored in carray 
if (res > 9)
		{
			carry = res / 10;
			res_str.push_back((res % 10) + '0');
		}