#!/usr/bin/python3
''' This module is used for getting information from an API '''
import json
import requests

if __name__ == "__main__":
    json_dict = {}
    response1 = requests.get(
        'https://jsonplaceholder.typicode.com/users')
    ret_dict = response1.json()
    for dicts in ret_dict:
        user_id = dicts["id"]
        tasks = requests.get(
            'https://jsonplaceholder.typicode.com/todos?userId={}'.format(
                user_id))
        tasks = tasks.json()
        for each in tasks:
            each.pop("userId", None)
            each.pop("id", None)
            task_name = each.pop("title", None)
            each["username"] = dicts["username"]
            each["task"] = task_name
        json_dict[str(user_id)] = tasks

    with open('todo_all_employees.json', 'w') as f:
        json.dump(json_dict, f)
