template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
    auto itr = std::equal_range(range_begin, range_end, prefix, 
        [prefix](std::string x)
        { 
            return x[0] == prefix;
        });
    return std::make_pair(itr.first, itr.second);
}
============================
    const std::vector<std::string> sorted_strings = { "moscow", "murmansk", "vologda" };
 
    const auto m_result = FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), 'm');
 
    for (auto it = m_result.first; it != m_result.second; ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;