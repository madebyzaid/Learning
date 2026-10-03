from bs4 import BeautifulSoup
import requests
url="https://www.youtube.com/watch?v=dQw4w9WgXcQ"
print(requests.get(url).reason)