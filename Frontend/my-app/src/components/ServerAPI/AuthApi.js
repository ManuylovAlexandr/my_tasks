import fetchJsonp from "fetch-jsonp";
import {request} from "./request";
import {API_BASE_URL} from "./utils";

export function getVkUser(token, userId) {
    let options = {
        url: "https://api.vk.com/method/users.get?user_ids=" + userId + "&fields=photo_50,domain&access_token=" + token + "&v=5.103",
        method: 'GET',
        redirect: 'follow'
    };

    return fetchJsonp(options.url, options)
        .then(response => {
                if (response.ok)
                    return response.json()
            }
        );
}

export function toVk(vk_data) {
    return request({
        url: API_BASE_URL + "/auth/vk/signin",
        method: 'POST',
        body: JSON.stringify(vk_data)
    });
}

