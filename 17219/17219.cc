#include <iostream>
#include <unordered_map>

int
main ()
{
  int N, M;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::unordered_map<std::string, std::string> url_to_pw;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    std::string url, pw;

    std::cin >> url >> pw;

    url_to_pw.insert (std::make_pair (url, pw));
  }

  for (int i = 0; i < M; ++i) {
    std::string url;

    std::cin >> url;
    std::cout << url_to_pw[url] << "\n";
  }
}
