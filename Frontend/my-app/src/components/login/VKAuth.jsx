import {toVk} from "../ServerAPI/AuthApi";
import React, {Component} from "react";
import {Loading} from "../Loading/Loading";

class VKAuth extends Component {
    constructor(props) {
        super(props);
        this.state = {
            client_id: "7457976",
            client_secret: "LjmDrYHnfZ8mFfKJQLMG",
            redirect_uri: window.location.protocol + "//" + window.location.host + "/vkauth",
            code: window.location.href.match(/code=(\w+)/)[1]
        };
        this.loadVkUser = this.loadVkUser.bind(this);
    }

    loadVkUser() {
        toVk(this.state).then(response => {
            localStorage.setItem('accessToken', response.accessToken);
            window.location.assign("/mainpage");
        })
    }

    componentDidMount() {
        this.loadVkUser();
    }

    render() {
        return (
           <Loading/>
        )

    }

}

export default VKAuth;