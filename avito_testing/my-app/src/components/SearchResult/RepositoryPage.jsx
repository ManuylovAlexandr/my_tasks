import style from "./RepositoryPage.module.css";
import {NavLink} from "react-router-dom";
import React, {Component} from "react";
import {getRepository, getLanguges, getContributors} from "../Server_API/request_functions"

class RepositoryPage extends Component {
    constructor(props) {
        super(props);
        this.state = {
            isLoaded: false,
            repos: null,
            langs: {},
            contributors: []
        };
    }

    loadRepos() {
        getRepository(this.props.match.params.owner, this.props.match.params.repos).then(response => {
            this.setState({
                repos: response,
                isLoaded: true
            });
        });
    }

    loadLanguages() {
        getLanguges(this.props.match.params.owner, this.props.match.params.repos).then(response => {
            this.setState({
                langs: response,
            });
        });
    }

    loadContributors() {
        getContributors(this.props.match.params.owner, this.props.match.params.repos).then(response => {
            this.setState({
                contributors: response,
            });
        });
    }

    componentDidMount() {
        this.loadRepos();
        this.loadLanguages();
        this.loadContributors();
    }

    render() {
        if (this.state.isLoaded) {
            let langsList = [<div className={style.langItemHeader}>Используемые языки:</div>];
            Object.keys(this.state.langs).forEach((item) => {
                langsList.push(<div className={style.langItem}>{item}</div>);
                langsList.push(<hr/>);
            });
            let contrList = [<div className={style.langItemHeader}>Контрибьюторы:</div>];
            this.state.contributors.forEach((item) => {
                contrList.push(<ContributorBlock avatarUrl={item.avatar_url} url={item.url} name={item.login}/>)
            });
            return (
                <div className={style.Wrapper}>
                    <NavLink className={style.ToMainPageLink} to="/mainpage">На главную</NavLink>
                    <br/>
                    <AuthorBlock avatarUrl={this.state.repos.owner.avatar_url}
                                 ownerUrl={this.state.repos.owner.html_url}
                                 Nick={this.state.repos.owner.login}/>
                    <ReposBlock reposName={this.state.repos.name} stars={this.state.repos.stargazers_count}
                                commit_date={this.state.repos.pushed_at}/>
                    <div className={style.Description}>
                        {this.state.repos.description}
                    </div>
                    <div className={style.Langs}>
                        {langsList}
                    </div>
                    <div className={style.ContrsBlock}>
                        {contrList}
                    </div>
                </div>
            );
        } else {
            return (
                <div className={style.Loading}>Loading . . .</div>
            )
        }
    };
}


function AuthorBlock(props) {
    return (
        <div className={style.AuthorBlock}>
            <a href={props.ownerUrl} target="_blank" className={style.AvatarLink}>
                <img src={props.avatarUrl} alt="" className={style.Avatar}/>
            </a>
            <a href={props.ownerUrl} target="_blank" className={style.LinkToOwner}>Автор: {props.Nick}</a>
        </div>
    );
}

function ReposBlock(props) {
    let str = props.commit_date, reg = /\d+/g;
    str = str.match(reg);
    return (
        <div className={style.ReposBlock}>
            <p className={style.reposText}>Репозиторий "{props.reposName}"</p>
            <p className={style.reposText}>звезд: {props.stars}</p>
            <p className={style.reposText}>Последний
                коммит: {str[2] + "." + str[1] + "." + str[0] + " " + str[3] + ":" + str[4] + ":" + str[5]}</p>
        </div>
    );
}

function ContributorBlock(props) {
    return (
        <a href={props.url} className={style.ContrLink}>
            <img src={props.avatarUrl} className={style.ContrAva}/>
            <p className={style.ContrName}>{props.name}</p>
        </a>
    );
}

export default RepositoryPage;