export function request(options) {
    const headers = new Headers({
        'Content-Type': 'application/json',
    });

    headers.append("Accept", "application/vnd.github.mercy-preview+json");
    headers.append("Accept", "application/vnd.github.nebula-preview+json");

    const defaults = {headers: headers};
    options = Object.assign({}, defaults, options);
    return fetch(options.url, options)
        .then(response =>
            response.json().then(json => {
                if (!response.ok) {
                    return Promise.reject(json);
                } else {
                    return Promise.resolve(json);
                }
            })
        );
}