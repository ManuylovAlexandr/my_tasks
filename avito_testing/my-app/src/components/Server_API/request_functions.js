import {request} from "./request.js"

export function Search(q, page) {
    return request({
        url: "https://api.github.com/search/repositories?q=" + q + "&sort=stars&order=desc?per_page=10&page=" + page,
        method: 'GET'
    });
}

export function getRepository(owner, repos) {
    return request({
        url: "https://api.github.com/repos/" + owner + "/" + repos,
        method: 'GET'
    });
}

export function getLanguges(owner, repos) {
    return request({
        url: "https://api.github.com/repos/" + owner + "/" + repos + "/languages",
        method: 'GET'
    });
}

export function getContributors(owner, repos) {
    return request({
        url: "https://api.github.com/repos/" + owner + "/" + repos + "/contributors?per_page=10",
        method: 'GET'
    });
}