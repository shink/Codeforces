/*
 * @author: shenke
 * @date: 2021/1/7
 * @project: Codeforces
 * @desp: 
 */

#include <iostream>

bool isRc(const std::string &str) {
    if (str[0] != 'R' || !isdigit(str[1]))
        return false;

    for (int i = 2; i < str.size(); ++i) {
        if (str[i] == 'C')
            return true;
    }

    return false;
}

int main() {
    int n;
    int idx, col;
    std::string str, res;
    char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        col = 0;

        std::cin >> str;
        if (isRc(str)) {
            // RXCY, R23C55 -> BC23
            idx = 1;
            while (str[idx] != 'C') {
                ++idx;
            }

            for (int j = idx + 1; j < str.size(); ++j) {
                col = col * 10 + str[j] - '0';
            }

            while (col) {
                int r = col % 26;
                col /= 26;

                if (r != 0) {
                    res += letter[r - 1];
                } else {
                    res += letter[25];
                    --col;
                }
            }

            for (int l = res.size() - 1; l >= 0; --l) {
                std::cout << res[l];
            }
            for (int k = 1; k < idx; ++k) {
                std::cout << str[k];
            }
            std::cout << '\n';
            res.clear();

        } else {
            // BC23 -> R23C55
            for (idx = 1; str[idx] > '9'; ++idx);

            for (int j = 0; j < idx; ++j) {
                col = col * 26 + str[j] - 'A' + 1;
            }

            std::cout << 'R';
            while (idx < str.size()) {
                std::cout << str[idx++];
            }
            std::cout << 'C' << col << '\n';
        }
    }

    return 0;
}
