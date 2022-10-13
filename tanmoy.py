import requests

def getRelevantFoodOutlets(city, maxCost):
    result = True
    page = 1
    answer = []

    while result:
        URL = f'https://jsonmock.hackerrank.com/api/food_outlets?city={city}&page={page}'
        r = requests.get(url = URL)
        response = r.json()

        total_pages = response["total_pages"]
        resuaurants_arr = response["data"]

        for rest in resuaurants_arr:
            rest_extimated_cost = rest["estimated_cost"]

            if rest_extimated_cost <= maxCost:
                answer.append(rest["name"])
        
        if (page == total_pages):
            result = False
        
        page = page + 1;

    
    return answer