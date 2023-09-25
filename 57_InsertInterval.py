class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if not intervals:
            res = [newInterval]
            return res
        start_i = newInterval[0]
        end_i = newInterval[1]
        start_flag = 0
        res_list = []
        for i in intervals:
            if not start_flag:
                if (i[0] <= start_i) and (i[1] >= start_i):
                    if i[1] >= end_i:
                        return intervals
                    else:
                        i[1] = end_i
                        res_list.append(i)
                        start_flag = 1
                elif i[0] >= start_i:
                    if i[0] > end_i:
                        res_list.append(newInterval)
                        res_list.append(i)
                    elif i[1] >= end_i:
                        i[0] = start_i
                        res_list.append(i)
                    else:
                        res_list.append(newInterval)
                    start_flag = 1
                else:
                    res_list.append(i)
            else:
                if i[0] > end_i:
                    res_list.append(i)
                elif i[1] >= end_i:
                    res_list[-1][1] = i[1]
        if not start_flag:
            res_list.append(newInterval)
        return res_list

        