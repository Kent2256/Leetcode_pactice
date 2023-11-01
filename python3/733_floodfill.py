class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        start_color = image[sr][sc]
        if start_color == color:
            return image
        self.flood_fill(image, sr, sc, start_color, color)
        return image

    def flood_fill(self, image, sr, sc, start_color, color):
            if sr < 0 or sr >= len(image): return
            if sc < 0 or sc >= len(image[0]): return

            if image[sr][sc] == color: return
            if image[sr][sc] != start_color: return

            image[sr][sc] = color

            self.flood_fill(image, sr-1, sc, start_color, color)
            self.flood_fill(image, sr+1, sc, start_color, color)
            self.flood_fill(image, sr, sc-1, start_color, color)
            self.flood_fill(image, sr, sc+1, start_color, color)


              



